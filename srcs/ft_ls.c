/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:14:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/18 19:47:03 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *getname_obj(t_dir *dir, t_obj *obj)
{
	char *tmp;

	tmp = NULL;
	if (dir && obj)
	{
		tmp = ft_strjoin(dir->dirname, "/");
		tmp = ft_strljoin(tmp, obj->entry->d_name);
	}
	return (tmp);
}

int		list_dir_buf(t_dir *dir)
{
	t_obj	*obj;
	char	*tmp;

	tmp = NULL;
	obj = obj_new_empty();
	if (!dir || (obj->entry = readdir(dir->dir)) == NULL)
	{
		free(obj->stat);
		free(obj);
		return (0);
	}
	tmp = getname_obj(dir, obj);
	if ((stat(tmp, obj->stat)) == -1)
	{
		free(obj->stat);
		free(obj);
		free(tmp);
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
	free(tmp);
	return (1);
}

static char *getname(char *dirname, t_dir *dir, int listn)
{
	char *tmp;
	
	tmp = NULL;
	if (dirname && dir)
	{
		tmp = ft_strjoin(dirname, "/");
		if (listn == LIST_DOT)
			tmp = ft_strljoin(tmp, DOT_NAME); 
		if (listn == LIST_CAP)
			tmp = ft_strljoin(tmp, CAP_NAME);
		if (listn == LIST_MIN)
			tmp = ft_strljoin(tmp, MIN_NAME); 
	}
	return (tmp);
}

int		list_dir(t_env *env, char *dirname)
{
	t_dir	*dir;
	char	*tmpdir;
	int		ret;

	ret = 0;
	printf("%s \n", dirname);
	if ((dir = dir_new(dirname)) == NULL)
		return (1);
	while ((ret = list_dir_buf(dir)) != 0)
		ret == -1 ? perror("ft_ls") : 0;
	print_dir(dir);
	// ajouter le flag pour la recursivite
	if (env->flag == 0)
	{
		dir_res_iter(dir);
		while (dir->i_cap)
		{
			if (CAP_TYPE == DT_DIR)
			{
				tmpdir = getname(dirname, dir, LIST_CAP);
				list_dir(env, tmpdir);
				free(tmpdir);
				tmpdir = NULL;
			}
			dir->i_cap = dir->i_cap->next;
		}
		while (dir->i_min)
		{
			if (MIN_TYPE == DT_DIR)
			{
				tmpdir = getname(dirname, dir, LIST_MIN);
				list_dir(env, tmpdir);
				free(tmpdir);
				tmpdir = NULL;
			}
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
	list_dir(&env, "/");
	return (0);
}
