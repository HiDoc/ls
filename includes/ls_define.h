/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:30:42 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/20 10:16:34 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_DEFINE_H
# define LS_DEFINE_H

# define LIST_DOT 1
# define LIST_CAP 2
# define LIST_MIN 3

# define FLAG_L (1U << 1)
# define FLAG_A (1U << 2)
# define FLAG_R (1U << 3)

# define DOT_TYPE dir->i_dot->entry->d_type
# define DOT_NAME dir->i_dot->entry->d_name
# define CAP_TYPE dir->i_cap->entry->d_type
# define CAP_NAME dir->i_cap->entry->d_name
# define MIN_TYPE dir->i_min->entry->d_type
# define MIN_NAME dir->i_min->entry->d_name

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

#endif
