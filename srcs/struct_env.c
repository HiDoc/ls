/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:46:36 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/17 17:02:50 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	env_init(t_env *env)
{
	env->flag = 0;
	env->f_dot = NULL;
	env->f_cap = NULL;
	env->f_min = NULL;
	env->i_dot = NULL;
	env->i_cap = NULL;
	env->i_min = NULL;
}
