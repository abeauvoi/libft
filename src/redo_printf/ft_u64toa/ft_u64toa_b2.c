/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 22:56:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 00:07:30 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_U64TOA_B2_TEST

# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

#endif

#include "ft_printf.h"

static const t_u8		digits2(uint64_t val)
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

t_u8					ft_u64toa_b2(uint64_t num, char *dst)
{
	static const t_u16	bdigits100[4] = { 0x3030, 0x3130, 0x3031, 0x3131};
	const t_u8			length = digits2(num);
	t_u8				next;

	next = length - 1;
	while (num >= 0b100)
	{
		*((int16_t *)(dst + next - 1)) = bdigits100[num % 0b100];
		num >>= 2;
		next -= 2;
	}
	if (num < 2)
		dst[next] = TO_CHAR(num);
	else
		*((int16_t *)(dst + next - 1)) = bdigits100[num];
	return (length);
}

#ifdef FT_U64TOA_B2_TEST

int			main(void)
{
	char		buf[INT_BUFSIZE_BOUND(uint64_t)];
	uint64_t	num;
	int 		i;

	i = 0;
	printf("TEST for ft_u64toa_b2 :\n");
	while (i < NTESTS)
	{
		printf("[test #%d]\n", i);
		arc4random_buf(&num, sizeof(num));
		buf[ft_u64toa_b2(num, buf)] = '\0';
		printf("[num:%lld]\n[res:%s]\n", num, buf);
		assert(strtoull(buf, NULL, 2) == num);
	}
	return (0);
}

#endif
