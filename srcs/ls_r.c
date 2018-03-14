/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:18:11 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/14 17:07:36 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


static void        ls_setfield(t_lists *lst, struct dirent *files, t_field *field)
{
	int            size;
	t_stat        *stat;

	size = 0;
	stat = NULL;
	if (ft_isupper(files->d_name[0]))
		stat = lst->iter_upper;
	else if (ft_islower(files->d_name[0]))
		stat = lst->iter_lower;
	if (stat && stat->filename)
	{
		if ((size = (int)ft_strlen(stat->filename)) > field->len_name)
			field->len_name = size;
	}
}

static void        ls_print(t_stat *iter, t_field *field)
{
	struct stat    stats;
	t_stat        *freestat;

	while (iter)
	{
		freestat = iter;
		stats = iter->v_stat;
		printf("%-*s ", field->len_name, iter->filename);
		iter = iter->next;
	}
}

static t_stat	*ls_r_get(char *dirname, t_field *field, struct dirent *files )
{
	t_lists        *lst;
	t_stat        *iter;
	DIR            *dir;

	if (!(dir = opendir(dirname)))
	{
		perror("Error :");
		return (NULL);
	}
	lst = ls_new_list();
	while ((files = readdir(dir)))
	{
		iter = new_stat(files->d_name, dirname);
		lst_append(lst, iter);
		ls_setfield(lst, files, field);
	}
	closedir(dir);
	if (lst->iter_upper && lst->first_lower)
		lst->iter_upper->next = lst->first_lower;
	else if (lst->first_lower && (!lst->first_upper))
		lst->first_upper = lst->first_lower;
	ls_print(lst->first_upper, field);
	return (lst->first_upper);
}

void	ls_r(struct dirent *files, char *dirname)
{
	t_stat	*stat;
	t_field	*field;
	char	*path;
	DIR		*dir;

	dir = opendir(dirname);
	printf("dirname : %s\n", dirname);
	field = ls_newfield();
	files = NULL;
	stat = ls_r_get(dirname, field, files);
	printf("\n");
	while (stat)
	{
		if (S_ISDIR(stat->v_stat.st_mode) && stat->filename[0] != '.' )
		{
			path = ft_strjoin(dirname, "/");
			path = ft_strjoin(path, stat->filename);
			ls_r(files, path);
			printf("\n");
		}
		stat = stat->next;
	}
}
