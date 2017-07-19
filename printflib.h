/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:35:57 by afeuerst          #+#    #+#             */
/*   Updated: 2017/07/19 14:24:43 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H
# define PRINTFLIB_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

# ifdef printf
#  undef printf
# endif

typedef struct		s_printfdata t_printfdata;

struct				s_printfdata
{
	uint64_t		data; // data
	size_t			data_lenght; // data lenght for push
	size_t			percent_lenght; // percent_lenght for increment
	int				percent_index_type; // percent conversion type // required for finding the corect function
	int				percent_index; // percent index location in string format
	t_printfdata	*next; // next % ?
};

int					printf(const char *const format, ...);

char				*string_printf(const char *format, va_list *args);

#endif
