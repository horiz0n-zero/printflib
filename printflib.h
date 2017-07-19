/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:35:57 by afeuerst          #+#    #+#             */
/*   Updated: 2017/07/19 14:05:08 by afeuerst         ###   ########.fr       */
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
	uint64_t		data;
	t_printfdata	*next;
};

int					printf(const char *const format, ...);

char				*string_printf(const char *format, va_list *args);

#endif
