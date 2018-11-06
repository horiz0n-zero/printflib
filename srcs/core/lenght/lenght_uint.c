/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:03:46 by afeuerst          #+#    #+#             */
/*   Updated: 2018/11/06 11:04:14 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static const int64_t	g_cut[8] =
{
	[1] = 0xFF,
	[2] = 0xFFFF,
	[3] = 0xFFFFFF,
	[4] = 0xFFFFFFFF,
};

static uint64_t			int_len(uint64_t value)
{
	uint64_t			len;

	len = 0;
	if (!value)
		return (1);
	while (value > 0)
	{
		value /= 10;
		len++;
	}
	return (len);
}

void					lenght_uint(t_printdata *data, va_list *args)
{
	uint64_t			len;

	if (!data->lenght)
		data->data = (int64_t)va_arg(*args, int32_t) & 0xFFFFFFFF;
	else if (data->lenght <= 4)
		data->data = ((int64_t)va_arg(*args, int32_t)) & g_cut[data->lenght];
	else
		data->data = va_arg(*args, int64_t);
	len = int_len((uint64_t)data->data);
	data->lenght = (uint16_t)len;
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
}
