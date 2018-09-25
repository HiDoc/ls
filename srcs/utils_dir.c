/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:11:27 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/25 17:05:42 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_includes.h"

static void	dir_add_dot(t_dir *dir, t_obj *add)
{
	if (dir->f_dot == NULL)
	{
		dir->f_dot = add;
		dir->i_dot = dir->f_dot;
	}
	else
	{
		dir->i_dot->next = add;
		dir->i_dot = dir->i_dot->next;
	}
}

static void	dir_add_cap(t_dir *dir, t_obj *add)
{
	if (dir->f_cap == NULL)
	{
		dir->f_cap = add;
		dir->i_cap = dir->f_cap;
	}
	else
	{
		dir->i_cap->next = add;
		dir->i_cap = dir->i_cap->next;
	}
}

static void	dir_add_min(t_dir *dir, t_obj *add)
{
	if (dir->f_min == NULL)
	{
		dir->f_min = add;
		dir->i_min = dir->f_min;
	}
	else
	{
		dir->i_min->next = add;
		dir->i_min = dir->i_min->next;
	}
}

void		dir_res_iter(t_dir *dir)
{
	dir->i_dot = dir->f_dot;
	dir->i_cap = dir->f_cap;
	dir->i_min = dir->f_min;
}

void		dir_add_list(t_dir *dir, t_obj *add, int listn)
{

	if (listn == LIST_DOT)
		dir_add_dot(dir, add);
	else if (listn == LIST_CAP)
		dir_add_cap(dir, add);
	else if (listn == LIST_MIN)
		dir_add_min(dir, add);
}
