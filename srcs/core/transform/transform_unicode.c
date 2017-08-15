#include "libprintf.h"

void					transform_unicode(t_printdata *data, char *dst)
{
	char 				*unicode = (void*)&data->data;

	while (data->lenght-- > 0)
		*dst++ = *unicode++;
}
