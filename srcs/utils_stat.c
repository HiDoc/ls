/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:46:34 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/18 13:10:15 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	stat_mode(mode_t st_mode, int isdir)
{
	char	protection[11];
	int		count;

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
