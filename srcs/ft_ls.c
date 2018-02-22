/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:55:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/22 16:47:27 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_stat	*new_stat(char *filename)
{
	t_stat	*new;

	if ((new = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if ((lstat(filename, &new->v_stat)))
		return (NULL);
	new->filename = ft_strdup(filename);
	new->grp = getgrgid(new->v_stat.st_gid);
	new->pwd = getpwuid(new->v_stat.st_uid);
	new->next = NULL;
	return (new);
}

static t_stat	*new_stat_a(char *filename)
{
	t_stat	*new;

	if ((new = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if ((lstat(filename, &new->v_stat)))
		return (NULL);
	new->filename = ft_strdup(filename);
	new->grp = NULL;
	new->pwd = NULL;
	new->next = NULL;
	return (new);
}

static void	ls_printa(t_stat *iter, t_field *field)
{
	struct stat 	stats;
	t_stat			*freestat;

	while (iter)
	{
		freestat = iter;
		stats = iter->v_stat;
		printf("%-*s ",field->len_name, iter->filename);
		free(iter->filename);
		iter = iter->next;
		free(freestat);
	}
}

static void	ls_printl(t_stat *iter, t_field *field)
{
	struct stat 	stats;
	t_stat			*freestat;

	while (iter)
	{
		freestat = iter;
		stats = iter->v_stat;
		if (iter->filename && iter->filename[0] == '.' && !S_ISDIR(stats.st_mode))
		{
			printf("%s  ", get_permissions(stats.st_mode));
			printf("%*hu ", field->len_link, stats.st_nlink);
			printf("%*s  ", field->len_suid, iter->pwd->pw_name);
			printf("%*s  ", field->len_guid, iter->grp->gr_name);
			printf("%*lld ", field->len_size, stats.st_size);
			printf("%*s ", field->len_date, format_time(ctime(&stats.st_mtime)));
			printf("%s\n", iter->filename);
		}
		free(iter->filename);
		iter = iter->next;
		free(freestat);
	}
}

static int	ls_getlen(unsigned long long len)
{
	unsigned long long	length;
	int 				ret;

	ret = 0;
	length = (long long unsigned)(len);
	while (length > 10)
	{
		length /= 10;
		ret++;
	}
	return (ret + 1);
}

static t_field	*ls_newfield(void)
{
	t_field *new;

	new = malloc(sizeof(t_field));
	new->len_link = 0;
	new->len_suid = 0;
	new->len_guid = 0;
	new->len_size = 0;
	new->len_date = 0;
	new->len_name = 0;
	return (new);
}

static void	ls_setfield(t_stat *stat, t_field *field)
{
	int			size;
	struct stat	cmp;

	size = 0;
	cmp = stat->v_stat;
	if ((size = ls_getlen(cmp.st_nlink)) > field->len_link)
		field->len_link = size;
	if ((size = (int)ft_strlen(stat->pwd->pw_name)) > field->len_suid)
		field->len_suid = size;
	if ((size = (int)ft_strlen(stat->grp->gr_name)) > field->len_guid)
		field->len_guid = size;
	if ((size = ls_getlen(cmp.st_size)) > field->len_size)
		field->len_size = size;
	if ((size = (int)ft_strlen(stat->filename)) > field->len_name)
		field->len_name = size;
}

static void	ls_setfield_a(t_stat *stat, t_field *field)
{
	int			size;

	size = 0;
	if ((size = (int)ft_strlen(stat->filename)) > field->len_name)
		field->len_name = size;
}

static void	ls_l(void)
{
	char 			*dirname = "./";
	DIR 			*dir = NULL;
	struct dirent	*files = NULL;
	t_stat			*first;
	t_stat			*iter;
	t_field			*field;

	field = ls_newfield();
	dir = opendir(dirname);
	if ((files = readdir(dir)))
	{
		if ((first = new_stat(files->d_name)) == NULL)
			return ;
		ls_setfield(first, field);
		iter = first;
	}
	while ((files = readdir(dir)))
	{
		iter->next = new_stat(files->d_name);
		iter = iter->next;
		ls_setfield(iter, field);
	}
	ls_printl(first, field);
}

static void	ls_a(void)
{
	char 			*dirname = "./";
	struct dirent	*files = NULL;
	DIR 			*dir = NULL;
	t_field			*field;
	t_stat			*first_upper;
	t_stat			*first_lower;
	t_stat			*first_dot;
	t_stat			*iter_upper;
	t_stat			*iter_lower;
	t_stat			*iter_dot;

	field = ls_newfield();
	dir = opendir(dirname);
	iter_upper = NULL;
	iter_lower = NULL;
	iter_dot = NULL;

	while ((files = readdir(dir)))
	{
		if (files->d_name[0] == '.')
		{
			if (!iter_dot)
			{
				first_dot = new_stat_a(files->d_name);
				iter_dot = first_dot;
				ls_setfield_a(first_dot, field);
			}
			else
			{
				iter_dot->next = new_stat_a(files->d_name);
				iter_dot = iter_dot->next;
				ls_setfield_a(iter_dot, field);
			}
		}
		else if (ft_isupper(files->d_name[0]))
		{
			if (!iter_upper)
			{
				first_upper = new_stat_a(files->d_name);
				iter_upper = first_upper;
				ls_setfield_a(first_upper, field);
			}
			else
			{
				iter_upper->next = new_stat_a(files->d_name);
				iter_upper = iter_upper->next;
				ls_setfield_a(iter_upper, field);
			}
		}
		else if (ft_islower(files->d_name[0]))
		{
			if (!iter_lower)
			{
				first_lower = new_stat_a(files->d_name);
				iter_lower = first_lower;
				ls_setfield_a(iter_lower, field);
			}
			else
			{
				iter_lower->next = new_stat_a(files->d_name);
				iter_lower = iter_lower->next;
				ls_setfield_a(iter_lower, field);
			}
		}
	}
	ls_printa(first_dot, field);
	ls_printa(first_upper, field);
	ls_printa(first_lower, field);
	printf("\n");
}
     #include <sys/ioctl.h>

int		main(void)
{
	struct ttysize ts;

	ioctl(0, TIOCGSIZE, &ts);
	printf ("lines %d\n", ts.ts_lines);
	printf ("columns %d\n", ts.ts_cols);
	(void)ls_l;	
	ls_a();
	return (0);
}
