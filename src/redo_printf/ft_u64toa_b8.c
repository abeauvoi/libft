/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:15:31 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 05:47:08 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

#endif
#include "ft_printf.h"

static const t_u8		digits8(uint64_t val)
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

static const t_u16		g_digits100[64] =
{
	0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3031,
	0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731, 0x3032, 0x3132,
	0x3232, 0x3332, 0x3432, 0x3532, 0x3632, 0x3732, 0x3033, 0x3133, 0x3233,
	0x3333, 0x3433, 0x3533, 0x3633, 0x3733, 0x3034, 0x3134, 0x3234, 0x3334,
	0x3434, 0x3534, 0x3634, 0x3734, 0x3035, 0x3135, 0x3235, 0x3335, 0x3435,
	0x3535, 0x3635, 0x3735, 0x3036, 0x3136, 0x3236, 0x3336, 0x3436, 0x3536,
	0x3636, 0x3736, 0x3037, 0x3137, 0x3237, 0x3337, 0x3437, 0x3537, 0x3637,
	0x3737
};

t_u8					ft_u64toa_b8(uint64_t num, char *dst)
{
	const t_u8	length = digits8(num);
	t_u8		next;

	next = length - 1;
	while (num >= 0100)
	{
		*((int16_t *)(dst + next - 1)) = g_digits100[num % 0100];
		num >>= 6;
		next -= 2;
	}
	if (num < 010)
		dst[next] = TO_CHAR(num);
	else
		*((int16_t *)(dst + next - 1)) = g_digits100[num];
	return (length);
}

#ifdef DEBUG

int						main(void)
{
	char		buf[INT_BUFSIZE_BOUND(uint64_t)];
	uint64_t	num;
	int			i;

	printf("TEST for ft_u64toa_b8:\n");
	i = 0;
	while (i < NTESTS)
	{
		printf("[test #%d]\n", i++);
		arc4random_buf(&num, sizeof(num));
		buf[ft_u64toa_b8(num, buf)] = '\0';
		printf("[num:%llo]\n[res:%s]\n", num, buf);
		assert(strtoull(buf, NULL, 8) == num);
	}
	return (0);
}
#endif
