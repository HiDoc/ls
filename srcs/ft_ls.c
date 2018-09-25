/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:14:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/25 17:03:26 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_includes.h"

static char *getname_obj(t_dir *dir, t_obj *obj)
{
	char *tmp;

	tmp = NULL;
	if (dir && obj)
	{
		tmp = ft_strjoin(dir->dirname, "/");
		if (ft_strcmp(tmp, "//") == 0)
		{
			free(tmp);
			tmp = ft_strdup("/");
		}
		tmp = ft_strljoin(tmp, obj->entry->d_name);
	}
	return (tmp);
}

static int list_free(t_obj *obj, char *tmp)
{
	if (obj)
	{
		free(obj->stat);
		if (obj->name)
			free(obj->name);
		free(obj);
	}
	if (tmp)
	{
		free(tmp);
		return (-1);
	}
	return (0);
}

int		list_dir_buf(t_dir *dir)
{
	t_obj	*obj;
	char	*tmp;

	tmp = NULL;
	obj = obj_new_empty();
	if (!dir || (obj->entry = readdir(dir->dir)) == NULL)
		return (list_free(obj, tmp));
	tmp = getname_obj(dir, obj);
	if ((stat(tmp, obj->stat)) == -1)
		return (list_free(obj, tmp));
	obj->name = strdup(obj->entry->d_name);
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

void	list_dir_iter(t_env *env, t_dir *dir, char *dirname, int listn)
{
	char *tmpdir;

	tmpdir = NULL;
	while (listn == LIST_CAP ? dir->i_cap : dir->i_min)
	{
		if ((listn == LIST_CAP ? CAP_TYPE : MIN_TYPE) == DT_DIR)
		{
			tmpdir = getname(dirname, dir, listn);
			printf("\n");
			list_dir(env, tmpdir);
			free(tmpdir);
			tmpdir = NULL;
		}
		listn == LIST_CAP ? dir->i_cap = dir->i_cap->next : 0;
		listn == LIST_MIN ? dir->i_min = dir->i_min->next : 0;
	}
}

int		list_dir(t_env *env, char *dirname)
{
	t_dir	*dir;
	int		ret;

	ret = 0;
	if (env->flag & FLAG_R)
		printf("%s\n", dirname);
	if ((dir = dir_new(env, dirname)) == NULL)
		return (1);
	while ((ret = list_dir_buf(dir)) != 0)
		ret == -1 ? perror("ft_ls") : 0;
	dir_res_iter(dir);
	print_dir(dir, env->flag);
	if (env->flag & FLAG_R)
	{
		list_dir_iter(env, dir, dirname, LIST_CAP);
		list_dir_iter(env, dir, dirname, LIST_MIN);
	}
	dir_del(dir);
	return (ret);
}

int		main(int argc, char **argv)
{
	t_env	env;

	env_init(&env, argc, argv);
	if (env.basedir != NULL)
	{
		list_dir(&env, env.basedir);
		free(env.basedir);
	}
	return (0);
}
