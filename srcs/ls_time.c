/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:32:39 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/22 13:44:56 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*format_time(char *tm)
{
	t_time	format;
	char	*tmp;

	format.split = ft_strsplit(tm, ' ');
	format.day = format.split[0];
	format.month = format.split[1];
	format.date = format.split[2];
	format.time = format.split[3];
	format.year = format.split[4];
	tmp = ft_strjoin(format.day, " ");
	tmp = ft_strljoin(tmp, format.date);
	tmp = ft_strljoin(tmp, " ");
	tmp = ft_strdjoin(tmp, ft_strsub(format.time, 0, 5));
	return (tmp);
}
