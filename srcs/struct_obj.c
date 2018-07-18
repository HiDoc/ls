/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:54:09 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/18 14:16:41 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_obj	*obj_new_empty(void)
{
	t_obj	*new;

	if ((new = (t_obj *)(malloc(sizeof(t_obj)))) == NULL)
		return (NULL);
	if ((new->stat = malloc(sizeof(struct stat))) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->entry = NULL;
	new->next = NULL;
	return (new);
}

t_obj	*obj_new(struct stat *stat, struct dirent *entry)
{
	t_obj	*new;

	if ((new = (t_obj *)(malloc(sizeof(t_obj)))) == NULL)
		return (NULL);
	new->stat = stat;
	new->entry = entry;
	new->next = NULL;
	return (new);
}
