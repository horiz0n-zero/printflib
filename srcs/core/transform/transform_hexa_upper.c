#include "libprintf.h"

static const char		upper[16] =
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'
};

static void 			push_hexa(t_printdata *data, char *dst)
{
	uint64_t 			value;

	value = (uint64_t)data->data;
	if (!value)
	{
		if (data->flags & POINT && !data->precision)
			return ;
		else
			*dst = '0';
	}
	while (value)
	{
		*dst-- = upper[value % 16];
		value /= 16;
	}
}

void					transform_hexa_upper(t_printdata *data, char *dst)
{
	const char 			pad = !data->precision && data->flags & ZERO ? '0' : ' ';

	if (data->flags & MINUS)
	{
		if (data->flags & HASH && data->data)
		{
			*dst++ = '0';
			*dst++ = 'X';
		}
		while (data->precision && data->precision--)
			*dst++ = '0';
		push_hexa(data, (dst += data->lenght) - 1);
		while (data->width-- > 0)
			*dst++ = ' ';
	}
	else
	{
		if (pad == ' ')
		{
			while (data->width-- > 0)
				*dst++ = pad;
		}
		if (data->flags & HASH && data->data)
		{
			*dst++ = '0';
			*dst++ = 'X';
		}
		if (pad == '0')
		{
			while (data->width-- > 0)
				*dst++ = '0';
		}
		while (data->precision && data->precision--)
			*dst++ = '0';
		push_hexa(data, (dst += data->lenght) - 1);
	}
}
