/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:46:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/25 14:25:40 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_includes.h"

void	stat_mode(mode_t st_mode, int isdir)
{
	char	protection[11];
	int		count;

	ft_bzero(protection, 11);
	count = 9;
	st_mode = st_mode & 0777;
	ft_strset((char *)protection, '-', 10);
	if (S_ISDIR(st_mode) || isdir)
		protection[0] = 'd';
	while (st_mode && count > 0)
	{
		protection[count--] = ((st_mode & 1) == 1) ? 'x' : '-';
		protection[count--] = ((st_mode & 2) == 2) ? 'w' : '-';
		protection[count--] = ((st_mode & 4) == 4) ? 'r' : '-';
		st_mode >>= 3;
	}
	printf("%-12s", protection);
}
