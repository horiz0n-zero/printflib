/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:05:58 by afeuerst          #+#    #+#             */
/*   Updated: 2017/07/19 14:10:41 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static size_t	ft_printf_strlen(const char *const str)
{
	size_t		size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int				ft_printf(const char *const format, ...)
{
	char		*string;
	va_list		args;
	int			len;

	va_start(args, format);
	string = string_printf(format, &args);
	va_end(args);
	if (string)
	{
		len = (int)ft_printf_strlen(string);
		write(STDIN_FILENO, string, (size_t)len);
		free(string);
		return (len);
	}
	return (0);
}
