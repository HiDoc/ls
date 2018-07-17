/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:06:09 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/17 17:53:11 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libftprintf.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <sys/dir.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <errno.h>

typedef struct	s_obj
{
	struct stat		*stat;
	struct dirent	*entry;
	struct s_obj	*next;
}				t_obj;
t_obj			*obj_new(struct stat *stat, struct dirent *entry);
t_obj			*obj_new_empty(void);

typedef struct	s_env
{
	struct s_obj	*f_dot;
	struct s_obj	*f_cap;
	struct s_obj	*f_min;
	struct s_obj	*i_dot;
	struct s_obj	*i_cap;
	struct s_obj	*i_min;
	unsigned int	flag;
}				t_env;
void			env_init(t_env *env);

void			print_dir(char *dirname);
char			*stat_mode(mode_t st_mode, int isdir);
void			env_add_list(t_env *env, t_obj *add, int listn);
#endif
