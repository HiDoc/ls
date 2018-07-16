/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:14:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/16 14:21:20 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		buf;

	(void)argc;
	(void)argv;
	dir = opendir(".");
	while ((entry = readdir(dir)) > 0)
	{
		stat(entry->d_name, &buf);
		printf("%-12s", stat_mode(buf.st_mode, (entry->d_type == 4)));
		printf("%2hu ", buf.st_nlink);
		printf("%-8s", getpwuid(buf.st_uid)->pw_name);
		printf("%-11s", getgrgid(buf.st_gid)->gr_name);
		printf("%4lld ", buf.st_size);
		printf("%ld", buf.st_mtime);
		printf("%-10s\n", entry->d_name);
	}
	return (0);
}
