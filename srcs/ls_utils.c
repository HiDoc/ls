/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:55:25 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/14 14:03:33 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ls_getlen(unsigned long long len)
{
	unsigned long long	length;
	int					ret;

	ret = 0;
	length = (long long unsigned)(len);
	while (length > 10)
	{
		length /= 10;
		ret++;
	}
	return (ret + 1);
}
