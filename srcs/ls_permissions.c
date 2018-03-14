/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:31:58 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/26 13:09:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_char(int num)
{
	if (!(num % 3))
		return ('x');
	else if (num % 3 == 2)
		return ('w');
	else
		return ('r');
}

char		*get_permissions(mode_t st_mode)
{
	char	perm[11];
	int		count;
	int		chmod;

	count = 9;
	chmod = st_mode % 512;
	while (count > 0)
	{
		if (chmod & 1)
			perm[count] = get_char(count);
		else
			perm[count] = '-';
		count--;
		chmod >>= 1;
	}
	perm[0] = (S_ISDIR(st_mode)) ? 'd' : '-';
	perm[10] = '\0';
	return (ft_strdup(perm));
}
