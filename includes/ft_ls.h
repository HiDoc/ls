/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:57:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/12 16:26:09 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <stdio.h>
# include "libftprintf.h"
typedef struct		s_stat
{
	struct stat 	v_stat;
	struct s_stat	*next;
	struct group	*grp;
	struct passwd	*pwd;
	char			*filename;
}					t_stat;

typedef struct		s_time
{
	char			**split;
	char			*day;
	char			*date;
	char			*month;
	char			*year;
	char			*time;
}					t_time;

typedef struct		s_field
{
	int				len_link;
	int				len_suid;
	int				len_guid;
	int				len_size;
	int				len_date;
	int				len_name;
}					t_field;

char				*get_permissions(mode_t st_mode);
char				*format_time(char *tm);
#endif
