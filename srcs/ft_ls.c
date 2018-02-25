/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:55:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/25 15:11:28 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(void)
{
	char			*dirname;
	struct dirent	*files;
	DIR				*dir;
	t_field			*field;
	(void)ls_l;

	files = NULL;
	field = ls_newfield();
	dirname = ft_strdup("./");
	dir = opendir(dirname);
	ls_a(files, dir, field);
	return (0);
}
