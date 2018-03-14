/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:52:07 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/27 11:35:48 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ls_colums(void)
{
	struct ttysize ts;

	ioctl(0, TIOCGSIZE, &ts);
	return (ts.ts_cols);
}

t_field		*ls_newfield(void)
{
	t_field *new;

	new = malloc(sizeof(t_field));
	new->len_link = 0;
	new->len_suid = 0;
	new->len_guid = 0;
	new->len_size = 0;
	new->len_date = 0;
	new->len_name = 0;
	new->len_cols = ls_colums();
	return (new);
}
