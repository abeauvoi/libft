/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 07:04:50 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 02:00:34 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			*call_va_arg(t_u32 state, va_list ap)
{
	if (state == MAXSTATE)
		return ;
	else if (state == INT)
		return ((void *)va_arg(ap, int));
	else if (state == UINT)
		return ((void *)va_arg(ap, unsigned int));
	else if (state == LONG)
		return ((void *)va_arg(ap, long int));
	else if (state == ULONG)
		return ((void *)va_arg(ap, unsigned long int));
	else if (state == SHORT)
		return ((void *)(t_s16)va_arg(ap, int));
	else if (state == USHORT)
		return ((void *)(t_u16)va_arg(ap, unsigned int));
	else if (state == CHAR)
		return ((void *)(char)va_arg(ap, int));
	else if (state == UCHAR)
		return ((void *)(t_u8)va_arg(ap, unsigned int));
}
