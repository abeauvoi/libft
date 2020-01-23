/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 19:34:45 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/01/23 20:29:12 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_memcpy_fast(uint8_t **u8dst, const uint8_t **u8src,
		size_t n)
{
	uint64_t		*u64dst;
	const uint64_t	*u64src;

	u64dst = (uint64_t *)*u8dst;
	u64src = (const uint64_t *)*u8src;
	n /= sizeof(uint64_t);
	while (n >= 4)
	{
		*u64dst++ = *u64src++;
		*u64dst++ = *u64src++;
		*u64dst++ = *u64src++;
		*u64dst++ = *u64src++;
		n -= 4;
	}
	while (n-- > 0)
		*u64dst++ = *u64src++;
	*u8dst = (uint8_t *)u64dst;
	*u8src = (const uint8_t *)u64src;
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint8_t			*u8dst;
	const uint8_t	*u8src;

	if (n == 0)
		return (dst);
	u8src = (const uint8_t *)src;
	u8dst = (uint8_t *)dst;
	if (n > 7 && ((uintptr_t)u8src & 7) == 0 && ((uintptr_t)u8dst & 7) == 0)
	{
		ft_memcpy_fast(&u8dst, &u8src, n);
		n &= 7;
	}
	while (n-- > 0)
		*u8dst++ = *u8src++;
	return (dst);
}
