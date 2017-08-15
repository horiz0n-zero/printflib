#include "libprintf.h"

static uint64_t 		int_len(uint64_t value)
{
	uint64_t 			len;

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

void					lenght_uint_long(t_printdata *data, va_list *args)
{
	uint64_t 			len;

	data->data = va_arg(*args, int64_t);
	len = int_len((uint64_t)data->data);
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
}
