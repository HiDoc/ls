/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:12:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/25 18:16:33 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_setfield(t_stat *stat, t_field *field)
{
	int			size;

	size = 0;
	if ((size = (int)ft_strlen(stat->filename)) > field->len_name)
		field->len_name = size;
}

static void		ls_print(t_stat *iter, t_field *field)
{
	struct stat	stats;
	t_stat		*freestat;

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

void			ls_a(struct dirent *files, DIR *dir, t_field *field)
{

	t_lists			*lst;
	lst = ls_new_list();

	while ((files = readdir(dir)))
	{
		lst_append(lst, files, field, files->d_name[0]);
		if (files->d_name[0] == '.')
			ls_setfield(lst->iter_dot, field);
		else if (ft_isupper(files->d_name[0]))
			ls_setfield(lst->iter_upper, field);
		else if (ft_islower(files->d_name[0]))
			ls_setfield(lst->iter_lower, field);
	}
	ls_print(lst->first_dot, field);
	ls_print(lst->first_upper, field);
	ls_print(lst->first_lower, field);
	printf("\n");
}
