/* ************************************************************************** */
/* m                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:55:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/14 16:04:36 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char			*dirname;
	struct dirent	*files;
	t_field			*field;
	size_t			count;

	if (argc > 1 && argc == 2)
	{
		count = 0;
		files = NULL;
		field = ls_newfield();
		dirname = ft_strdup(argv[1]);
		ls_r(files, dirname);
	}
	return (0);
}
