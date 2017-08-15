
#include "libprintf.h"

static void 				ft_printfEndFunction(const char *const src, t_printinfo *const info)
{
	info->total_len--;
	info->data = write(STDOUT_FILENO, src, info->total_len);
}

int 						ft_printf(const char *format, ...)
{
	static t_printdata 		*element = NULL;
	static t_printinfo 		info =
	{
		&element,
		NULL,
		(void*)ft_printfEndFunction,
		1, // total len + '\0'
		0
	};
	va_list 				args;

	va_start(args, format);
	info.args = &args;
	printf_exec(format, &info, info.first_element);
	va_end(args);
	return ((int)info.total_len);
}
