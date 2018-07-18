/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:14:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/18 15:17:27 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		list_dir_buf(t_dir *dir)
{
	t_obj	*obj;

	obj = obj_new_empty();
	if ((obj->entry = readdir(dir->dir)) == NULL)
	{
		free(obj->stat);
		free(obj);
		perror("ft_ls:");
		return (0);
	}
	printf("hello :%s\n", obj->entry->d_name);
	if ((stat(obj->entry->d_name, obj->stat)) == -1)
	{
		free(obj->stat);
		free(obj);
		perror("ls");
		return (-1);
	}
	if (obj->entry->d_name[0])
	{
		if (obj->entry->d_name[0] == '.')
			dir_add_list(dir, obj, LIST_DOT);
		else if (ft_isupper(obj->entry->d_name[0]))
			dir_add_list(dir, obj, LIST_CAP);
		else
			dir_add_list(dir, obj, LIST_MIN);
	}
	return (1);
}

int		list_dir(t_env *env, char *dirname)
{
	t_dir	*dir;
	int		ret;

	ret = 0;
	printf("%s \n", dirname);
	dir = dir_new(dirname);
	while ((ret = list_dir_buf(dir)) != 0)
		;
	print_dir(dir);
	if (env->flag == 0)
	{
		dir_res_iter(dir);
		while (dir->i_cap)
		{
			dir->i_cap->entry->d_type == DT_DIR ? list_dir(env, dir->i_cap->entry->d_name) : 0;
			dir->i_cap = dir->i_cap->next;
		}
		while (dir->i_min)
		{
			dir->i_min->entry->d_type == DT_DIR ? list_dir(env, dir->i_min->entry->d_name) : 0;
			dir->i_min = dir->i_min->next;
		}
	}
	dir_del(dir);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_env	env;

	env_init(&env);
	(void)argc;
	(void)argv;
	list_dir(&env, ".");
	return (0);
}
