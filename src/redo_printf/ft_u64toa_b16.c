/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 08:12:13 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 10:26:50 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

FORCE_INLINE static const size_t	digits16(uint64_t val)
{
	if (val < POW_16(P01))
		return (1);
	if (val < POW_16(P02))
		return (2);
	if (val < POW_16(P03))
		return (3);
	if (val < POW_16(P12))
	{
		if (val < POW_16(P08))
		{
			if (val < POW_16(P06))
			{
				if (val < POW_16(P04))
					return (4);
				return (5 + (val >= POW_16(P05)));
			}
			return (7 + (val >= POW_16(P07)));
		}
		if (val < POW_16(P10))
			return (9 + (val >= POW_16(P09)));
		return (11 + (val >= POW_16(P11)));
	}
	return (12 + digits16(val / POW_16(P12)));
}

/*
** i => [0..511] so we need i to be an unsigned int16_t  !!
** @param to_lowercase must be either 0x0 or 0x2020
*/

size_t							ft_u64toa_b16(uint64_t num, char *dst,
		uint16_t to_lowercase)
{
	static const char	lut[sizeof(INIT_LUT_U64TOA_B16)] =
		INIT_LUT_U64TOA_B16;
	const size_t		length = digits16(num);
	uint32_t			next;
	uint16_t			i;

	next = length - 1;
	while (num >= 0x100)
	{
		i = (num & 0xFF) << 1;
		num >>= 8;
		*((int16_t *)(dst + next - 1)) = *((int16_t *)(lut + i)) | to_lowercase;
		next -= 2;
	}
	if (num < 0x10)
		dst[next] = (char)(XDIGITS_U[(uint32_t)num] | to_lowercase);
	else
		*((int16_t *)(dst + next - 1)) = *((int16_t *)(lut + ((uint32_t)num << 1)))
			| to_lowercase;
	return (length);
}

#ifdef TEST
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int			main(int argc, char *const argv[])
{
	char		buf[INT_BUFSIZE_BOUND(uint64_t)];
	uint64_t	num;
	uint16_t 	to_lowercase = (argc == 2 && ft_strcmp(argv[1], "-l") == 0 ? 0x2020 : 0);

	printf("TEST for ft_u64toa_b16 :\n");
	for (int i = 0;i<2000;++i) {
		printf("[test #%d]\n", i);
		arc4random_buf(&num, sizeof(num));
		buf[ft_u64toa_b16(num, buf, to_lowercase)] = '\0';
		printf("[num:%llx]\n[res:%s]\n", num, buf);
		assert(strtoull(buf, NULL, 16) == num);
	}
	return (0);
}
#endif