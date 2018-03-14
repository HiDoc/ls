/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:46:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/14 15:57:24 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_print(t_stat *iter, t_field *field)
{
	struct stat	stats;
	t_stat		*freestat;

	while (iter)
	{
		freestat = iter;
		stats = iter->v_stat;
		if (iter->filename && iter->filename[0] != '.')
		{
			printf("%s  ", get_permissions(stats.st_mode));
			printf("%*hu ", field->len_link, stats.st_nlink);
			printf("%*s  ", field->len_suid, iter->pwd->pw_name);
			printf("%*s  ", field->len_guid, iter->grp->gr_name);
			printf("%*lld ", field->len_size, stats.st_size);
			printf("%*s ", field->len_date,
				format_time(ctime(&stats.st_mtime)));
			printf("%s\n", iter->filename);
		}
		free(iter->filename);
		iter = iter->next;
		free(freestat);
	}
}

static void		ls_setfield(t_stat *stat, t_field *field)
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

void			ls_l(struct dirent *files, DIR *dir, t_field *field)
{
	t_lists		*lst;
	t_stat		*iter;

	lst = ls_new_list();
	while ((files = readdir(dir)))
	{
		iter = new_stat(files->d_name, files->d_name);
		lst_append(lst, iter);
		if (files->d_name[0] == '.')
			ls_setfield(lst->iter_dot, field);
		else if (ft_isupper(files->d_name[0]))
			ls_setfield(lst->iter_upper, field);
		else if (ft_islower(files->d_name[0]))
			ls_setfield(lst->iter_lower, field);
	}
	ls_print(lst->first_upper, field);
	ls_print(lst->first_lower, field);
	printf("\n");
}
