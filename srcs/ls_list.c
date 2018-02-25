/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:27:33 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/25 18:12:00 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lists	*ls_new_list(void)
{
	t_lists		*new;

	if ((new = (t_lists *)malloc(sizeof(t_lists))) == NULL)
		return (NULL);
	new->first_upper = NULL;
	new->first_lower = NULL;
	new->first_dot = NULL;
	new->iter_upper = NULL;
	new->iter_lower = NULL;
	new->iter_dot = NULL;
	return (new);
}


static t_stat        *lst_switch(char c, t_lists *lst, int first)
{
	if (c == '.' && first)
		return (lst->first_dot);
	if (c == '.' && !first)
		return (lst->iter_dot);
	if (ft_isupper(c) && first)
		return (lst->first_upper);
	if (ft_isupper(c) && !first)
		return (lst->iter_upper);
	if (ft_islower(c) && first)
		return (lst->first_lower);
	if (ft_islower(c) && !first)
		return (lst->iter_lower);
	return (NULL);
}

static t_lists        *lst_reverse_switch(char c, t_lists *lst, int first, t_stat *stat)
{
	if (c == '.' && first)
		(lst->first_dot = stat);
	if (c == '.' && !first)
		(lst->iter_dot = stat);
	if (ft_isupper(c) && first)
		(lst->first_upper = stat);
	if (ft_isupper(c) && !first)
		(lst->iter_upper = stat);
	if (ft_islower(c) && first)
		(lst->first_lower = stat);
	if (ft_islower(c) && !first)
		(lst->iter_lower = stat);
	return (lst);
}

t_lists            *lst_append(t_lists *lst, struct dirent *files, t_field *field, char c)
{
	t_stat    *iter;
	t_stat    *first;

	(void)field;
	iter = lst_switch(c, lst, 0);
	first = lst_switch(c, lst, 1);
	if (!iter)
	{
		first = new_stat(files->d_name);
		iter = first;
	}
	else
	{
		iter->next = new_stat(files->d_name);
		iter = iter->next;
	}
	lst_reverse_switch(c, lst, 0, iter);
	lst_reverse_switch(c, lst, 1, first);
	return (lst);
}
