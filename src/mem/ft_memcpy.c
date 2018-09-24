/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 19:34:45 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 18:35:22 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_memcpy_fast(uint8_t **dst, const uint8_t **src,
		size_t n)
{
	uint64_t		*adst;
	const uint64_t	*asrc;

	adst = (uint64_t *)*dst;
	asrc = (const uint64_t *)*src;
	while (n >= sizeof(uint64_t) * 4)
	{
		*adst++ = *asrc++;
		*adst++ = *asrc++;
		*adst++ = *asrc++;
		*adst++ = *asrc++;
		n -= sizeof(uint64_t) * 4;
	}
	while (n >= sizeof(uint64_t))
	{
		*adst++ = *asrc++;
		n -= sizeof(uint64_t);
	}
	*dst = (uint8_t *)adst;
	*src = (const uint8_t *)asrc;
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
				&& ft_isaligned(src, sizeof(uint64_t))
				&& ft_isaligned(dst, sizeof(uint64_t)))
		{
			ft_memcpy_fast(&dst, &src, n);
			n %= sizeof(uint64_t);
		}
		while (n-- > 0)
			*dst++ = *src++;
	}
	return (dst0);
}
