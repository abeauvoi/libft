/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:43:39 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/01/23 20:26:21 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void 	*ft_memset_fast(uint8_t *u8dst, uint64_t value, size_t n)
{
	uint64_t	*u64dst;

	u64dst = (uint64_t *)u8dst;
	n /= 8;
	while (n >= 4)
	{
		*u64dst++ = value;
		*u64dst++ = value;
		*u64dst++ = value;
		*u64dst++ = value;
		n -= 4;
	}
	while (n-- > 0)
		*u64dst++ = value;
	return (u64dst);
}

void			*ft_memset(void *dst0, int c, size_t n)
{
	uint8_t		*u8dst;
	uint8_t		uc;

	if (n == 0)
		return (0);
	u8dst = (uint8_t *)dst0;
	uc = (uint8_t)c;
	while (n-- > 0 && ((uintptr_t)u8dst & 7) != 0)
		*u8dst++ = uc;
	if (n >= sizeof(uintptr_t))
	{
		u8dst = ft_memset_fast(u8dst, 0x0101010101010101ULL * uc, n);
		n &= 7;
	}
	while (n-- > 0)
		*dst++ = uc;
	return (dst0);
}
