/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 19:34:45 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/25 20:10:04 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_memcpy_fast(uint8_t **ucdst, const uint8_t **ucsrc,
		size_t n)
{
	uint64_t		*ulldst;
	const uint64_t	*ullsrc;

	ulldst = (uint64_t *)*ucdst;
	ullsrc = (const uint64_t *)*ucsrc;
	n /= 8;
	while (n >= 4)
	{
		*ulldst++ = *ullsrc++;
		*ulldst++ = *ullsrc++;
		*ulldst++ = *ullsrc++;
		*ulldst++ = *ullsrc++;
		n -= 4;
	}
	while (n-- > 0)
		*ulldst++ = *ullsrc++;
	*ucdst = (uint8_t *)ulldst;
	*ucsrc = (const uint8_t *)ullsrc;
}

void			*ft_memcpy(void *dst0, const void *src0, size_t n)
{
	uint8_t			*ucdst;
	const uint8_t	*ucsrc;

	if (n == 0)
		return (dst0);
	ucsrc = (const uint8_t *)src0;
	ucdst = (uint8_t *)dst0;
	if (n > 7
			&& ((uintptr_t)ucsrc & 7) == 0
			&& ((uintptr_t)ucdst & 7) == 0)
	{
		ft_memcpy_fast(&ucdst, &ucsrc, n);
		n &= 7;
	}
	while (n-- > 0)
		*ucdst++ = *ucsrc++;
	return (dst0);
}
