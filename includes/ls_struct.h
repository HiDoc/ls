/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:30:54 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/25 17:01:25 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_STRUCT_H
# define LS_STRUCT_H

typedef struct s_obj	t_obj;
typedef struct s_env	t_env;
typedef struct s_dir	t_dir;

struct	s_env
{
	char			*basedir;
	unsigned int	flag;
};

struct	s_obj
{
	struct stat		*stat;
	struct dirent	*entry;
	struct s_obj	*next;
	char			*name;
};

struct	s_dir
{
	t_env			*env;
	DIR				*dir;
	char			*dirname;
	struct s_obj	*f_dot;
	struct s_obj	*f_cap;
	struct s_obj	*f_min;
	struct s_obj	*i_dot;
	struct s_obj	*i_cap;
	struct s_obj	*i_min;
};
#endif
