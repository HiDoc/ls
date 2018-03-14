/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:08:06 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/14 15:35:32 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lists			*ls_new_list(void)
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

static t_stat	*lst_switch(char c, t_lists *lst, int first)
{
	if (c == '.' && first)
		return (lst->first_dot);
	else if (c == '.' && !first)
		return (lst->iter_dot);
	else if (ft_isupper(c) && first)
		return (lst->first_upper);
	else if (ft_isupper(c) && !first)
		return (lst->iter_upper);
	else if (ft_islower(c) && first)
		return (lst->first_lower);
	else if (ft_islower(c) && !first)
		return (lst->iter_lower);
	return (NULL);
}

static t_lists	*lst_reverse_switch(
		char c, t_lists *lst, int first, t_stat *stat)
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

t_lists			*lst_append(t_lists *lst, t_stat *stat)
{
	t_stat	*first;
	t_stat	*iter;
	int 	c;

	c = stat->filename[0];
	iter = lst_switch(c, lst, 0);
	first = lst_switch(c, lst, 1);
	if (!first)
	{
		first = stat;
		iter = first;
		lst_reverse_switch(c, lst, 1, first);
	}
	else
	{
		iter->next = stat;
		iter = iter->next;
	}
	lst_reverse_switch(c, lst, 0, iter);
	return (lst);
}
