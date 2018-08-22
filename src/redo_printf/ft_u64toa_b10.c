/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 05:45:52 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 09:18:34 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** u64toa implementation based on :
** https://www.facebook.com/notes/facebook-engineering/three-optimization-tips-\
** for-c/10151361643253920
*/

FORCE_INLINE static const size_t	digits10(uint64_t val)
{
	if (val < P01)
		return (1);
	if (val < P02)
		return (2);
	if (val < P03)
		return (3);
	if (val < P12)
	{
		if (val < P08)
		{
			if (val < P06)
			{
				if (val < P04)
					return (4);
				return (5 + (val >= P05));
			}
			return (7 + (val >= P07));
		}
		if (val < P10)
			return (9 + (val >= P09));
		return (11 + (val >= P11));
	}
	return (12 + digits10(val / P12));
}

/*
** The lookup table encodes every possible remainder of n/100 => 00, 01, etc
** This function writes 2 char at once with a cast of the lut ptr to short
*/

size_t 								ft_u64toa_b10(uint64_t num, char *dst)
{
	static const char	lut[sizeof(INIT_LUT_U64TOA_B10)] =
		INIT_LUT_U64TOA_B10;
	const size_t		length = digits10(num);
	uint32_t			next;
	uint8_t				i;

	next = length - 1;
	while (num >= 100)
	{
		i = (num % 100) << 1;
		num /= 100;
		*((short*)(dst + next - 1)) = *((short*)(lut + i));
		next -= 2;
	}
	if (num < 10)
		dst[next] = TO_CHAR((uint32_t)num);
	else
	{
		i = ((uint32_t)num << 1);
		dst[next] = lut[i + 1];
		dst[next - 1] = lut[i];
	}
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

	printf("TEST for ft_u64toa_b10 :\n");
	for (int i = 0;i<2000;++i) {
		printf("[test #%d]\n", i);
		arc4random_buf(&num, sizeof(num));
		len = ft_u64toa_b10(num, buf);
		buf[len] = '\0';
		printf("[num:%llu]\n[res:%s]\n", num, buf);
		assert(strtoull(buf, NULL, 10) == num);
	}
	return (0);
}
#endif
