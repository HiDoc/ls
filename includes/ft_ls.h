/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:57:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/25 18:08:27 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS_H
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

typedef struct		s_stat
{
	struct stat 	v_stat;
	struct s_stat	*next;
	struct group	*grp;
	struct passwd	*pwd;
	char			*filename;
}					t_stat;

typedef struct		s_lists
{
	struct s_stat	*first_upper;
	struct s_stat	*first_lower;
	struct s_stat	*first_dot;
	struct s_stat	*iter_upper;
	struct s_stat	*iter_lower;
	struct s_stat	*iter_dot;
}					t_lists;

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
	int				len_cols;
}					t_field;

char				*get_permissions(mode_t st_mode);
char				*format_time(char *tm);

int					ls_getlen(unsigned long long len);

t_field				*ls_newfield(void);

t_stat				*new_stat(char *filename);

t_lists				*ls_new_list(void);
t_lists				*lst_append(t_lists *lst, struct dirent *files, t_field *field, char c);

void				ls_a(struct dirent *f, DIR *d, t_field *fl);
void				ls_l(struct dirent *f, DIR *d, t_field *fl);
#endif
