/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:46:36 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/25 15:55:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_includes.h"

void	env_free(t_env *env)
{
	free(env->basedir);
}

void	env_flag(t_env *env, char *str)
{
	if (*str == '-')
	{
		++str;
		while (*str)
		{
			if (*str == 'l')
				env->flag |= FLAG_L;
			if (*str == 'r')
				env->flag |= FLAG_R;
			if (*str == 'a')
				env->flag |= FLAG_A;
			++str;
		}
	}
	else if (env->basedir == NULL)
		env->basedir = ft_strdup(str);
}

void	env_init(t_env *env, int argc, char **argv)
{
	int count;

	count = 1;
	env->flag = 0;
	env->basedir = NULL;
	if (argc > 1)
	{
		while (count < argc)
		{
			env_flag(env, argv[count]);
			count++;
		}
	}
	if (env->basedir == NULL)
		env->basedir = ft_strdup(".");
}
