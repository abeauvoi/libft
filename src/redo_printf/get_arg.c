/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 07:04:50 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 07:16:49 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void			get_arg(union u_arg *arg, uint8_t type, va_list ap)
{
	if (type > MAXSTATE)
		return ;
	else if (type == CHAR)
		arg->i = (char)va_arg(ap, int32_t);
	else if (type == UCHAR)
		arg->i = (uint8_t)va_arg(ap, int32_t);
	else if (type == SHORT)
		arg->i = (int16_t)va_arg(ap, int32_t);
	else if (type == USHORT)
		arg->i = (uint16_t)va_arg(ap, int32_t);
	else if (type == INT)
		arg->i = va_arg(ap, int32_t);
	else if (type == UINT)
		arg->i = va_arg(ap, uint32_t);
	else if (type == LONG)
		arg->i = va_arg(ap, int64_t);
	else if (type == ULONG)
		arg->i = va_arg(ap, uint64_t);
	else if (type == PTR)
		arg->p = va_arg(ap, void *);
}
