/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:55:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/11 17:54:49 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(void)
{
	char *dirname = "./";
	DIR *dir = NULL;
	struct dirent *files = NULL;
	struct stat stats;

	dir = opendir(dirname);
	while ((files = readdir(dir)))
	{
		if (!(lstat(files->d_name, &stats)))
			get_permissions(stats.st_mode);
		printf("%s \n", files->d_name);
	}
	return (0);
}
