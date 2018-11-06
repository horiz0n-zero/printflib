/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_int_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:01:39 by afeuerst          #+#    #+#             */
/*   Updated: 2018/11/06 11:02:03 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static uint64_t			int_len(int64_t value)
{
	uint64_t			len;

	len = 0;
	if (value < 0)
		value = -value;
	else if (!value)
		return (1);
	while (value > 0)
	{
		value /= 10;
		len++;
	}
	return (len);
}

static void				add_spec(t_printdata *data)
{
	if (data->data < 0)
		data->len++;
	else
	{
		if (data->flags & (PLUS | SPACE))
			data->len++;
	}
}

void					lenght_int_long(t_printdata *data, va_list *args)
{
	uint64_t			len;

	data->data = va_arg(*args, int64_t);
	len = int_len(data->data);
	data->lenght = (uint32_t)len;
	if (data->precision > len)
		data->precision -= len;
	else
		data->precision = 0;
	data->len = data->precision + len;
	if (data->width > data->len)
	{
		data->width -= data->len;
		data->len += data->width;
	}
	else
		data->width = 0;
	add_spec(data);
}
