/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:11:27 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/17 17:49:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	env_add_dot(t_env *env, t_obj *add)
{
	if (env->f_dot == NULL)
	{
		env->f_dot = add;
		env->i_dot = env->f_dot;	
	}
	else
	{
		env->i_dot->next = add;
		env->i_dot = env->i_dot->next;
	}
}

static void	env_add_cap(t_env *env, t_obj *add)
{
	if (env->f_cap == NULL)
	{
		env->f_cap = add;
		env->i_cap = env->f_cap;	
	}
	else
	{
		env->i_cap->next = add;
		env->i_cap = env->i_cap->next;
	}
}

static void	env_add_min(t_env *env, t_obj *add)
{
	if (env->f_min == NULL)
	{
		env->f_min = add;
		env->i_min = env->f_min;	
	}
	else
	{
		env->i_min->next = add;
		env->i_min = env->i_min->next;
	}
}

void		env_add_list(t_env *env, t_obj *add, int listn)
{
	if (listn == 1)
		env_add_dot(env, add);
	else if (listn == 2)
		env_add_cap(env, add);
	else if (listn == 3)
		env_add_min(env, add);
}
