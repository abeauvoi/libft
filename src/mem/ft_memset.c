/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:43:39 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/25 20:04:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void 	*ft_memset_fast(uint8_t *ucdst, uint64_t value, size_t n)
{
	uint64_t	*ulldst;

	ulldst = (uint64_t *)ucdst;
	n /= 8;
	while (n >= 4)
	{
		*ulldst++ = value;
		*ulldst++ = value;
		*ulldst++ = value;
		*ulldst++ = value;
		n -= 4;
	}
	while (n-- > 0)
		*ulldst++ = value;
	return (ulldst);
}

void			*ft_memset(void *dst0, int c, size_t n)
{
	uint8_t		*ucdst;
	uint8_t		uc;

	if (n == 0)
		return (0);
	ucdst = (uint8_t *)dst0;
	uc = (uint8_t)c;
	while (n-- > 0 && ((uintptr_t)ucdst & 7) != 0)
		*ucdst++ = uc;
	if (n > 7)
	{
		ucdst = ft_memset_fast(ucdst, 0x0101010101010101ULL * uc, n);
		n &= 7;
	}
	while (n-- > 0)
		*dst++ = uc;
	return (dst0);
}
