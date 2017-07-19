/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfdata_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:50:08 by afeuerst          #+#    #+#             */
/*   Updated: 2017/07/19 14:16:53 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

// arriver directe avec le %

void				*printfdata_init(const char *input)
{
	t_printfdata	*new;

	new = malloc(sizeof(*new));

	return (new);
}
