/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:57:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 18:37:23 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_memmove_fast(uint8_t **dst, const uint8_t **src,
		size_t n)
{
	uint64_t		*wdst;
	const uint64_t	*wsrc;
	
	wdst = (uint64_t *)*dst;
	wsrc = (uint64_t *)*src;
	while (n >= sizeof(uint64_t) * 4)
	{
		*--wdst = *--wsrc;
		*--wdst = *--wsrc;
		*--wdst = *--wsrc;
		*--wdst = *--wsrc;
		n -= sizeof(uint64_t) * 4;
	}
	while (n >= sizeof(uint64_t))
	{
		*--wdst = *--wsrc;
		n -= sizeof(uint64_t);
	}
	*dst = (uint8_t*)wdst;
	*src = (const uint8_t*)wsrc;
}

void					*ft_memmove(void *dst, const void *src, size_t n)
{
	uint8_t			*d;
	const uint8_t	*s;

	d = (uint8_t *)dst;
	s = (const uint8_t *)src;
	if (s < d && d < s + n)
	{
		s += n;
		d += n;
		if (n > sizeof(uint64_t)
				&& ft_isaligned(s, sizeof(uint64_t))
				&& ft_isaligned(d, sizeof(uint64_t)))
		{
			ft_memmove_fast(&d, &s, n);
			n %= sizeof(uint64_t);
		}
		while (n-- > 0)
			*--d = *--s;
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, n));
}
