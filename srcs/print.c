/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:52:02 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/17 17:09:08 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_dir(char *dirname)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		buf;

	dir = opendir(dirname);
	while ((entry = readdir(dir)) > 0)
	{
		stat(entry->d_name, &buf);
		printf("%-12s", stat_mode(buf.st_mode, (entry->d_type == 4)));
		printf("%2hu ", buf.st_nlink);
		printf("%-9s", getpwuid(buf.st_uid)->pw_name);
		printf("%-12s", getgrgid(buf.st_gid)->gr_name);
		printf("%4lld ", buf.st_size);
		printf("%.12s ", &ctime(&buf.st_mtime)[4]);
		printf("%-10s\n", entry->d_name);
	}
	closedir(dir);
}
