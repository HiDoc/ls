/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:27:07 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/25 17:03:11 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_includes.h"

static inline void	dir_del_iter(t_obj *first, t_obj *iter)
{
	while (iter)
	{
		first = iter->next;
		free(iter->stat);
		free(iter->name);
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

t_dir				*dir_new(t_env *env, char *dirname)
{
	t_dir	*dir;

	if ((dir = malloc(sizeof(t_dir))) == NULL)
		return (NULL);
	if ((dir->dir = opendir(dirname)) == NULL)
	{
		free(dir);
		perror("ft_ls");
		return (NULL);
	}
	dir->env = env;
	dir->dirname = dirname;
	dir->f_dot = NULL;
	dir->f_cap = NULL;
	dir->f_min = NULL;
	dir->i_dot = NULL;
	dir->i_cap = NULL;
	dir->i_min = NULL;
	return (dir);
}
