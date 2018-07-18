/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:52:02 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/18 13:12:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

inline static void	dir_print_all(t_obj *obj)
{
	if (obj)
	{
		stat_mode(obj->stat->st_mode, (obj->entry->d_type == 4));
		printf("%2hu ", obj->stat->st_nlink);
		printf("%-9s", getpwuid(obj->stat->st_uid)->pw_name);
		printf("%-12s", getgrgid(obj->stat->st_gid)->gr_name);
		printf("%4lld ", obj->stat->st_size);
		printf("%.12s ", &ctime(&obj->stat->st_mtime)[4]);
		printf("%-10s\n", obj->entry->d_name);
	}
}

void				print_dir(t_dir *dir)
{
	dir->i_dot = dir->f_dot;
	dir->i_cap = dir->f_cap;
	dir->i_min = dir->f_min;
	while (dir->i_dot)
	{
		dir_print_all(dir->i_dot);
		dir->i_dot = dir->i_dot->next;
	}
	while (dir->i_cap)
	{
		dir_print_all(dir->i_cap);
		dir->i_cap = dir->i_cap->next;
	}
	while (dir->i_min)
	{
		dir_print_all(dir->i_min);
		dir->i_min = dir->i_min->next;
	}
}
