/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:12:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/14 15:57:27 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_setfield(t_lists *lst, struct dirent *files, t_field *field)
{
	int			size;
	t_stat		*stat;

	size = 0;
	stat = NULL;
	if (files->d_name[0] == '.')
		stat = lst->iter_dot;
	else if (ft_isupper(files->d_name[0]))
		stat = lst->iter_upper;
	else if (ft_islower(files->d_name[0]))
		stat = lst->iter_lower;
	if (stat && stat->filename)
	{
		if ((size = (int)ft_strlen(stat->filename)) > field->len_name)
			field->len_name = size;
	}
}

static void		ls_print(t_stat *iter, t_field *field)
{
	struct stat	stats;
	t_stat		*freestat;

	while (iter)
	{
		freestat = iter;
		stats = iter->v_stat;
		printf("%-*s ", field->len_name, iter->filename);
		iter = iter->next;
	}
}

static t_lists	*ls_chain(t_lists *lst)
{
	if (lst->first_upper)
	{
		lst->iter_dot->next = lst->first_upper;
	}
	else if (lst->first_lower)
	{
		lst->iter_dot->next = lst->first_lower;
	}
	if (lst->iter_upper)
	{
		lst->iter_upper->next = lst->first_lower;
	}
	return (lst);
}

t_stat			*ls_a(struct dirent *files, char *dirname, t_field *field)
{
	t_lists		*lst;
	t_stat		*iter;
	DIR			*dir;

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
	ls_chain(lst);
	ls_print(lst->first_dot, field);
	return (lst->first_dot);
}
