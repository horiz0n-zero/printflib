
#include "libprintf.h"

void				transform_char(t_printdata *data, char *dst)
{
	const char 		pad = data->flags & ZERO ? '0' : ' ';
	const char 		c = (char)data->data;

	if (data->flags & MINUS)
	{
		*dst++ = c;
		while (data->width--)
			*dst++ = ' ';
	}
	else
	{
		while (data->width-- > 1)
			*dst++ = pad;
		*dst = c;
	}
}
