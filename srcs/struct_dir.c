/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:27:07 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/18 15:12:05 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	dir_del_iter(t_obj *first, t_obj *iter)
{
	while (iter)
	{
		first = iter->next;
		free(iter->stat);
		free(iter);
		iter = first;
	}
}

void				dir_del(t_dir *dir)
{
	closedir(dir->dir);
	dir_res_iter(dir);
	dir_del_iter(dir->f_dot, dir->i_dot);
	dir_del_iter(dir->f_cap, dir->i_cap);
	dir_del_iter(dir->f_min, dir->i_min);
	free(dir);
}

t_dir				*dir_new(char *dirname)
{
	t_dir	*dir;

	if ((dir = malloc(sizeof(t_dir))) == NULL)
		return (NULL);
	dir->dir = opendir(dirname);
	dir->f_dot = NULL;
	dir->f_cap = NULL;
	dir->f_min = NULL;
	dir->i_dot = NULL;
	dir->i_cap = NULL;
	dir->i_min = NULL;
	return (dir);
}
