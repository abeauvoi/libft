/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 19:34:45 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:56:23 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_memcpy_fast(uint8_t **dst, const uint8_t **src,
		size_t n)
{
	uint64_t		*lwdst;
	const uint64_t	*lwsrc;

	lwdst = (uint64_t *)*dst;
	lwsrc = (const uint64_t *)*src;
	n /= sizeof(uint64_t);
	while (n >= 4)
	{
		*lwdst++ = *lwsrc++;
		*lwdst++ = *lwsrc++;
		*lwdst++ = *lwsrc++;
		*lwdst++ = *lwsrc++;
		n -= 4;
	}
	while (n-- > 0)
		*lwdst++ = *lwsrc++;
	*dst = (uint8_t *)lwdst;
	*src = (const uint8_t *)lwsrc;
}

void					*ft_memcpy(void *dst0, const void *src0, size_t n)
{
	uint8_t			*dst;
	const uint8_t	*src;

	if (n)
	{
		src = (const uint8_t *)src0;
		dst = (uint8_t *)dst0;
		if (n >= sizeof(uint64_t)
				&& ft_isaligned((const void *)src, sizeof(uint64_t))
				&& ft_isaligned((const void *)dst, sizeof(uint64_t)))
		{
			ft_memcpy_fast(&dst, &src, n);
			n %= sizeof(uint64_t);
		}
		while (n-- > 0)
			*dst++ = *src++;
	}
	return (dst0);
}
