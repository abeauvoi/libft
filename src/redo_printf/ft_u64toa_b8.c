/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:15:31 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 10:32:06 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

FORCE_INLINE static const size_t	digits8(uint64_t val)
{
	if (val < POW_8(P01))
		return (1);
	if (val < POW_8(P02))
		return (2);
	if (val < POW_8(P03))
		return (3);
	if (val < POW_8(P12))
	{
		if (val < POW_8(P08))
		{
			if (val < POW_8(P06))
			{
				if (val < POW_8(P04))
					return (4);
				return (5 + (val >= POW_8(P05)));
			}
			return (7 + (val >= POW_8(P07)));
		}
		if (val < POW_8(P10))
			return (9 + (val >= POW_8(P09)));
		return (11 + (val >= POW_8(P11)));
	}
	return (12 + digits8(val / POW_8(P12)));
}

size_t								ft_u64toa_b8(uint64_t num, char *dst)
{
	static const char	lookup_table[sizeof(INIT_LU_TABLE_ITOA_B8)] =
		INIT_LU_TABLE_ITOA_B8;
	const size_t		length = digits8(num);
	uint32_t			next;
	uint8_t				i;

	next = length - 1;
	while (num >= 0100)
	{
		i = (num & 077) << 1;
		num >>= 6;
		dst[next] = lookup_table[i + 1];
		dst[next - 1] = lookup_table[i];
		next -= 2;
	}
	if (num < 010)
		dst[next] = TO_CHAR((uint32_t)num);
	else
	{
		i = ((uint32_t)num << 1);
		dst[next] = lookup_table[i + 1];
		dst[next - 1] = lookup_table[i];
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

	printf("TEST for ft_u64toa_b8 :\n");
	for (int i = 0;i<2000;++i) {
		printf("[test #%d]\n", i);
		arc4random_buf(&num, sizeof(num));
		len = ft_u64toa_b8(num, buf);
		buf[len] = '\0';
		printf("[num:%llo]\n[res:%s]\n", num, buf);
		assert(strtoull(buf, NULL, 8) == num);
	}
	return (0);
}
#endif

