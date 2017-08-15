#include "libprintf.h"

static uint64_t		hexa_len(t_printdata *data)
{
	uint64_t 		len;
	uint64_t 		value;

	value = (uint64_t)data->data;
	len = 0;
	if (!value)
	{
		if (data->flags & POINT && data->precision == 0)
			return (0);
		return (1);
	}
	while (value)
	{
		len++;
		value /= 16;
	}
	return (len);
}

static const int64_t 	cut[8] =
{
	[1] = 0xFF,
	[2] = 0xFFFF
};

void					lenght_hexa(t_printdata *data, va_list *args)
{
	uint64_t 			len;

	if (!data->lenght)
		data->data = (int64_t)va_arg(*args, int32_t) & 0xFFFFFFFF;
	else if (data->lenght <= 4)
		data->data = ((int64_t)va_arg(*args, int32_t)) & cut[data->lenght];
	else
		data->data = va_arg(*args, int64_t);
	len = hexa_len(data);
	data->lenght = (uint32_t)len;
	if (data->flags & HASH && data->data)
		len += 2;
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
