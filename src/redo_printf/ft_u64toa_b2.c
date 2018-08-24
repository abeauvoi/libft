/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 22:56:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/23 23:19:44 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const size_t		digits2(uint64_t val)
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

size_t					ft_u64toa_b2(uint64_t num, char *dst)
{
	static const char	lut[sizeof("0000000100100011010001010110011110001001101010111100110111101111")] = "00011011";
	const size_t		length = digits2(num);
	uint32_t			next;
	uint8_t				i;

	next = length - 1;
	while (num >= POW_2(2))
	{
		i = (num & (POW_2(2) - 1)) << 1;
		num >>= 2;
		*((int16_t *)(dst + next - 1)) = *((int16_t *)(lut + i));
		next -= 2;
	}
	if (num < 2)
		dst[next] = TO_CHAR(num);
	else
		*((int16_t *)(dst + next - 1))
			= *((int16_t *)(lut + ((uint32_t)num << i)));
	return (length);
}

#ifdef TEST
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int			main(void)
{
	char		buf[INT_BUFSIZE_BOUND(uint64_t)];
	size_t		len;
	uint64_t	num;

	printf("TEST for ft_u64toa_b2 :\n");
	printf("POW_2(2):%u\nPOW_2(1):%u\n", POW_2(2));
	for (int i = 0;i<2000;++i) {
		printf("[test #%d]\n", i);
		arc4random_buf(&num, sizeof(num));
		len = ft_u64toa_b2(num, buf);
		buf[len] = '\0';
		printf("[num:%lld]\n[res:%s]\n", num, buf);
		assert(strtoull(buf, NULL, 2) == num);
	}
	return (0);
}
#endif
