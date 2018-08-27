/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u64toa_b10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 05:45:52 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 05:46:38 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

#endif
#include "ft_printf.h"

/*
** itoa implementation based on : https://bit.ly/1npWQAB
*/

static const t_u8	digits10(uint64_t val)
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
** Little-endian binary lookup table of every ascii digit pair of mod 256 values
*/

static const t_u16	g_digits100[100] =
{
	0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3830,
	0x3930, 0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731,
	0x3831, 0x3931, 0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632,
	0x3732, 0x3832, 0x3932, 0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533,
	0x3633, 0x3733, 0x3833, 0x3933, 0x3034, 0x3134, 0x3234, 0x3334, 0x3434,
	0x3534, 0x3634, 0x3734, 0x3834, 0x3934, 0x3035, 0x3135, 0x3235, 0x3335,
	0x3435, 0x3535, 0x3635, 0x3735, 0x3835, 0x3935, 0x3036, 0x3136, 0x3236,
	0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 0x3836, 0x3936, 0x3037, 0x3137,
	0x3237, 0x3337, 0x3437, 0x3537, 0x3637, 0x3737, 0x3837, 0x3937, 0x3038,
	0x3138, 0x3238, 0x3338, 0x3438, 0x3538, 0x3638, 0x3738, 0x3838, 0x3938,
	0x3039, 0x3139, 0x3239, 0x3339, 0x3439, 0x3539, 0x3639, 0x3739, 0x3839,
	0x3939
};

t_u8				ft_u64toa_b10(uint64_t num, char *dst)
{
	const t_u8 	length = digits10(num);
	t_u8		next;

	next = length - 1;
	while (num >= 100)
	{
		*((int16_t *)(dst + next - 1)) = g_digits100[num % 100];
		num /= 100;
		next -= 2;
	}
	if (num < 10)
		dst[next] = TO_CHAR(num);
	else
		*((int16_t *)(dst + next - 1)) = g_digits100[num];
	return (length);
}

#ifdef DEBUG

int					main(void)
{
	char		buf[INT_BUFSIZE_BOUND(uint64_t)];
	uint64_t	num;
	int			i;

	printf("DEBUG for ft_u64toa_b10 :\n");
	i = 0;
	while (i < NTESTS)
	{
		printf("[test #%d]\n", i);
		++i;
		arc4random_buf(&num, sizeof(num));
		buf[ft_u64toa_b10(num, buf)] = '\0';
		printf("[num:%llu]\n[buf:%s]\n", num, buf);
		assert(strtoull(buf, NULL, 10) == num);
	}
	return (0);
}
#endif
