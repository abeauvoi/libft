/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 22:56:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:09:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uint8_t			digits2(uint64_t val)
{
	if (val < POW_2(1))
		return (1);
	if (val < POW_2(2))
		return (2);
	if (val < POW_2(3))
		return (3);
	if (val < POW_2(12))
	{
		if (val < POW_2(8))
		{
			if (val < POW_2(6))
			{
				if (val < POW_2(4))
					return (4);
				return (5 + (val >= POW_2(5)));
			}
			return (7 + (val >= POW_2(7)));
		}
		if (val < POW_2(10))
			return (9 + (val >= POW_2(9)));
		return (11 + (val >= POW_2(11)));
	}
	return (12 + digits2(val / POW_2(12)));
}

uint8_t					ft_u64toa_b2(uint64_t num, char *dst)
{
	static const uint16_t	bdigits100[4] = { 0x3030, 0x3130, 0x3031, 0x3131 };
	const uint8_t			length = digits2(num);
	uint8_t					next;

	next = length - 1;
	while (num >= 4)
	{
		*((uint16_t *)(dst + next - 1)) = bdigits100[num % 4];
		num >>= 2;
		next -= 2;
	}
	if (num < 2)
		dst[next] = num - '0';
	else
		*((uint16_t *)(dst + next - 1)) = bdigits100[num];
	return (length);
}
