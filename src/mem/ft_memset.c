/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:43:39 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:02:34 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_memset_fast(uint8_t **dst, uint64_t lword, size_t n)
{
	uint64_t	*wptr;

	wptr = (uint64_t *)*dst;
	n >>= 3;
	while (n >= 4)
	{
		wptr[0] = lword;
		wptr[1] = lword;
		wptr[2] = lword;
		wptr[3] = lword;
		wptr += 4;
		n -= 4;
	}
	while (n-- > 0)
		*wptr++ = lword;
	*dst = (uint8_t *)wptr;
}

void					*ft_memset(void *dst0, int c, size_t n)
{
	uint8_t		*dst;
	uint64_t	lword;

	if (n)
	{
		dst = (uint8_t *)dst0;
		while (!ft_isaligned((const void *)dst, sizeof(lword)))
		{
			*dst++ = (uint8_t)c;
			if (--n == 0 || *dst == '\0')
				return (dst0);
		}
		if (n >= sizeof(lword) * 4)
		{
			lword = 0x010101010101010101ULL * (uint8_t)c;
			ft_memset_fast(&dst, lword, n);
			n &= sizeof(lword) - 1;
		}
		while (n-- > 0)
			*dst++ = (uint8_t)c;
	}
	return (dst0);
}
