/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 07:04:50 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:07:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*call_va_arg(uint32_t state, va_list ap)
{
	if (state == PTR)
		return ((void *)(uintptr_t)va_arg(ap, char *));
	else if (state == INT)
		return ((void *)(uintptr_t)va_arg(ap, int));
	else if (state == UINT)
		return ((void *)(uintptr_t)va_arg(ap, unsigned int));
	else if (state == LONG)
		return ((void *)(uintptr_t)va_arg(ap, long int));
	else if (state == ULONG)
		return ((void *)(uintptr_t)va_arg(ap, unsigned long int));
	else if (state == SHORT)
		return ((void *)(uintptr_t)(uint16_t)va_arg(ap, int));
	else if (state == USHORT)
		return ((void *)(uintptr_t)(uint16_t)va_arg(ap, unsigned int));
	else if (state == CHAR)
		return ((void *)(uintptr_t)(char)va_arg(ap, int));
	else if (state == UCHAR)
		return ((void *)(uintptr_t)(uint8_t)va_arg(ap, unsigned int));
	else
		return (NULL);
}
