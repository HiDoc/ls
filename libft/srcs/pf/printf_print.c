/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:51:57 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/01 14:39:41 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			print_buffer(char *str, int freestr)
{
	char	buffer[SPEED + 2];
	size_t	len;
	size_t	count;

	(void)(freestr);
	buffer[SPEED + 1] = '\0';
	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		count = 0;
		ft_bzero(buffer, SPEED);
		while (count < len)
		{
			ft_bzero(buffer, SPEED);
			write(1, buffer, ft_strlcpy(buffer, &str[count], SPEED - 1));
			count += SPEED - 1;
		}
	}
	return ((int)len);
}

static int	print_check_next(t_arg *arg, size_t len, char *str)
{
	if (arg->error == 0)
	{
		if (arg->next == NULL)
			len += print_buffer(str, 1);
		else if ((!is_str(arg->next) && !arg->next->islower) || checkwstr(arg))
			len += print_buffer(str, 1);
		else if (!is_char(arg->next) || checkwchar(arg->next->char0))
			len += print_buffer(str, 1);
		return (len);
	}
	return (-1);
}

static int	print_error(t_arg *arg)
{
	if (arg->hformat)
	{
		free(arg->hformat);
		arg->hformat = NULL;
	}
	if (arg->format)
	{
		free(arg->format);
		arg->format = NULL;
	}
	return (-1);
}

int			print_args(t_arg *arg, size_t len, int percent, int error)
{
	(void)percent;
	while (arg)
	{
		if (is_char(arg))
		{
			if ((error = print_wchar(arg)) == -1)
				return (-1);
			len += error;
		}
		else
		{
			if (is_str(arg) && !arg->islower)
			{
				if (!checkwstr(arg))
					return (print_error(arg));
				len += print_bigstr(arg);
			}
			len = print_check_next(arg, len, arg->format);
		}
		arg = arg->next;
	}
	return ((int)len);
}
