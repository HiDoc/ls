/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:31:58 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/11 17:54:52 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_permissions(mode_t st_mode)
{
	char perm[11];

	int count = 0;
	while (count < 10)
	{
		perm[count] = '-';
		count++;	
	}
	perm[10] = '\0';
	if (S_ISDIR(st_mode))
		perm[0] = 'd';
	printf("%o ",st_mode );
	(void)st_mode;
	return (0);
}
