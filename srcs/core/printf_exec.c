
# include "libprintf.h"

static const lenght_func		g_functions_lenght[] =
{
	[PRINT_ERROR] = lenght_void, // bad % description
	[PRINT_PERCENT] = lenght_percent,
	[PRINT_S] = lenght_string,
	[PRINT_SS] = lenght_unicode_string,
	[PRINT_P] = lenght_pointer,
	[PRINT_D] = lenght_int,
	[PRINT_DD] = lenght_int_long,
	[PRINT_I] = lenght_int,
	[PRINT_O] = lenght_octal,
	[PRINT_OO] = lenght_octal_long,
	[PRINT_U] = lenght_uint,
	[PRINT_UU] = lenght_uint_long,
	[PRINT_X] = lenght_hexa,
	[PRINT_XX] = lenght_hexa,
	[PRINT_C] = lenght_percent,
	[PRINT_CC] = lenght_unicode

};

static const transform_func 	g_functions_transform[] =
{
	[PRINT_ERROR] = transform_void,
	[PRINT_PERCENT] = transform_percent,
	[PRINT_S] = transform_string,
	[PRINT_SS] = transform_unicode_string,
	[PRINT_P] = transform_pointer,
	[PRINT_D] = transform_int,
	[PRINT_DD] = transform_int,
	[PRINT_I] = transform_int,
	[PRINT_O] = transform_octal,
	[PRINT_OO] = transform_octal,
	[PRINT_U] = transform_uint,
	[PRINT_UU] = transform_uint,
	[PRINT_X] = transform_hexa_lower,
	[PRINT_XX] = transform_hexa_upper,
	[PRINT_C] = transform_char,
	[PRINT_CC] = transform_unicode
};

static void 					printf_calculate(t_printinfo *const info, const char *const src)
{
	uint32_t					index;
	t_printdata					*data;
	char						buffer[info->total_len];
	uint32_t					buffer_index;

	index = 0;
	buffer_index = 0;
	data = *(t_printdata**)info->first_element;
	while (src[index])
	{
		if (src[index] == '%')
		{
			g_functions_transform[data->conversion](data, buffer + buffer_index);
			index = data->end_index;
			buffer_index += data->len;
			data = data->next;
		}
		else
			buffer[buffer_index++] = src[index++];
	}
	buffer[buffer_index] = 0;
	((void (*)(const char *const, t_printinfo *const))info->function)(buffer, info);
} 

static void 					printf_precalculate(t_printinfo *const info)
{
	t_printdata					*data;

	data = *(t_printdata**)info->first_element;
	while (data)
	{
		g_functions_lenght[data->conversion](data, info->args);
		printf("[%s%s%s%s%s%s][%llu][%llu][%u][%u] len: %llu\n", 
								data->flags & MINUS ? "-" : "*",
								data->flags & PLUS ? "+" : "*",
								data->flags & SPACE ? " " : "*",
								data->flags & ZERO ? "0" : "*",
								data->flags & HASH ? "#" : "*", 
								data->flags & POINT ? "." : "*", 
								data->width, data->precision, data->lenght, data->conversion, data->len);
		
		info->total_len += data->len;
		data = data->next;
	}	
}

void							printf_exec(const char *const src, t_printinfo *const info, t_printdata **next)
{
	static uint32_t 			index = 0;
	static void *const 			index_ptr = &index;
	t_printdata 				data;
	static const t_printdata 	def = {0, 0, 0, 0, 0, 0, 0, 0, NULL};

	while (src[index] && src[index] != '%')
	{
		index++;
		info->total_len++;
	}
	if (src[index] == '%')
	{
		*next = &data;
		data = def;
		index++;
		printf_get_data(src, index_ptr, &data);
		printf("[%s%s%s%s%s%s][%llu][%llu][%u][%u] len: %llu\n", 
								data.flags & MINUS ? "-" : "*",
								data.flags & PLUS ? "+" : "*",
								data.flags & SPACE ? " " : "*",
								data.flags & ZERO ? "0" : "*",
								data.flags & HASH ? "#" : "*", 
								data.flags & POINT ? "." : "*", 
								data.width, data.precision, data.lenght, data.conversion, data.len);
		printf_exec(src, info, &data.next);
	}
	else if (!src[index])
	{
		index = 0;
		printf_precalculate(info);
		printf_calculate(info, src);
	}
}
