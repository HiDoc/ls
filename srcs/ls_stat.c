/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:06:40 by fmadura           #+#    #+#             */
/*   Updated: 2018/02/25 18:07:12 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat    *new_stat(char *filename)
{
	t_stat	*new;

	if ((new = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if ((lstat(filename, &new->v_stat)))
		return (NULL);
	new->filename = ft_strdup(filename);
	new->grp = getgrgid(new->v_stat.st_gid);
	new->pwd = getpwuid(new->v_stat.st_uid);
	new->next = NULL;
	return (new);
}
