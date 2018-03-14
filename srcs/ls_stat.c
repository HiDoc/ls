/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:06:40 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/14 17:07:51 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat	*new_stat(char *filename, char *dirname)
{
	t_stat	*new;
	char 	*path;

	path = ft_strjoin(dirname, "/");
	path = ft_strljoin(path, filename);
	if ((new = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if ((lstat(path, &new->v_stat)))
	{
		perror("Error :");
		return (NULL);
	}
	new->filename = ft_strdup(filename);
	new->grp = getgrgid(new->v_stat.st_gid);
	new->pwd = getpwuid(new->v_stat.st_uid);
	new->next = NULL;
	free(path);
	return (new);
}
