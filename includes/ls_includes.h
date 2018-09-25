/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_includes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:29:26 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/20 10:20:12 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INCLUDES_H
# define LS_INCLUDES_H
# include "ls_define.h"
# include "ls_struct.h"

t_obj			*obj_new_empty(void);
t_dir			*dir_new(t_env *env, char *dirname);
void			dir_del(t_dir *dir);
void			dir_res_iter(t_dir *dir);
void			dir_add_list(t_dir *dir, t_obj *add, int listn);

void			env_init(t_env *env, int argc, char **argv);

int				list_dir(t_env *env, char *tmpdir);
void			print_dir(t_dir *dir, int flags);
void			stat_mode(mode_t st_mode, int isdir);
#endif
