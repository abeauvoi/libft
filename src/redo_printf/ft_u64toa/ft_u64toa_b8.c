/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:15:31 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:10:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t						ft_u64toa_b8(uint64_t num, char *dst)
{
	const uint16_t	digits64[64] = { 0x3030, 0x3130, 0x3230, 0x3330, 0x3430,
		0x3530, 0x3630, 0x3730, 0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531,
		0x3631, 0x3731, 0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632,
		0x3732, 0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533, 0x3633, 0x3733,
		0x3034, 0x3134, 0x3234, 0x3334, 0x3434, 0x3534, 0x3634, 0x3734, 0x3035,
		0x3135, 0x3235, 0x3335, 0x3435, 0x3535, 0x3635, 0x3735, 0x3036, 0x3136,
		0x3236, 0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 0x3037, 0x3137, 0x3237,
		0x3337, 0x3437, 0x3537, 0x3637, 0x3737 };
	const uint8_t	length = ft_nbrlen_b8(num);
	uint8_t			next;

	next = length - 1;
	while (num >= 64)
	{
		*((uint16_t *)(dst + next - 1)) = digits64[num % 64];
		num >>= 6;
		next -= 2;
	}
	if (num < 8)
		dst[next] = num - '0';
	else
		*((uint16_t *)(dst + next - 1)) = digits64[num];
	return (length);
}
