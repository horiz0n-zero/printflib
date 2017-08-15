#include "libprintf.h"

void					lenght_percent(t_printdata *data, va_list *args)
{
	data->data = ((int64_t)va_arg(*args, int)) & 0xFF;
	if (data->width)
		data->len = data->width;
	else
		data->len = 1;
}
