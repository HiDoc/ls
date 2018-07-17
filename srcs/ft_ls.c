/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:14:22 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/17 17:53:10 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_dir(t_env *env, char *dirname)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		buf;

	(void)env;
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

int		main(int argc, char **argv)
{
	t_env	env;

	env_init(&env);
	(void)argc;
	(void)argv;
	print_dir(".");
	return (0);
}
