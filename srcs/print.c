/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:52:02 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/25 17:05:41 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_includes.h"

inline static void	dir_print_all(t_obj *obj, int flags)
{
	if (obj)
	{
		if (flags & FLAG_L)
		{
			stat_mode(obj->stat->st_mode, (obj->entry->d_type == 4));
			printf("%2hu ", obj->stat->st_nlink);
			if (getpwuid(obj->stat->st_uid))
				printf("%-9s", getpwuid(obj->stat->st_uid)->pw_name);
			if (getgrgid(obj->stat->st_gid))
				printf("%-12s", getgrgid(obj->stat->st_gid)->gr_name);
			if (getgrgid(obj->stat->st_gid))
				printf("%4lld ", obj->stat->st_size);
			printf("%.12s ", &ctime(&obj->stat->st_mtime)[4]);
		}
		printf("%s\n", obj->name);
	}
}

void				print_dir(t_dir *dir, int flags)
{
	if (dir)
	{
		dir_res_iter(dir);
		if (flags & FLAG_A)
			while (dir->i_dot)
			{
				dir_print_all(dir->i_dot, flags);
				dir->i_dot = dir->i_dot->next;
			}
		while (dir->i_cap)
		{
			dir_print_all(dir->i_cap, flags);
			dir->i_cap = dir->i_cap->next;
		}
		while (dir->i_min)
		{
			dir_print_all(dir->i_min, flags);
			dir->i_min = dir->i_min->next;
		}
	}
}
