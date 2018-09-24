/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:43:39 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/18 22:25:35 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_memset_fast(uint8_t **dst, uint64_t word, size_t n)
{
	uint64_t	*wptr;

	wptr = (uint64_t *)*dst;
	while (n >= sizeof(word) * 4)
	{
		wptr[0] = word;
		wptr[1] = word;
		wptr[2] = word;
		wptr[3] = word;
		wptr += 4;
		n -= sizeof(word) * 4;
	}
	while (n >= sizeof(word))
	{
		*wptr = word;
		++wptr;
		n -= sizeof(word);
	}
	*dst = (uint8_t *)wptr;
}

void					*ft_memset(void *dst0, int c, size_t n)
{
	uint8_t		*dst;
	uint32_t	uc;
	uint64_t	word;

	if (n)
	{
		dst = (uint8_t *)dst0;
		uc = (uint16_t)c;
		while (!ft_isaligned((const void *)dst, sizeof(word)))
		{
			*dst++ = uc;
			if (--n == 0 || *dst == '\0')
				return (dst0);
		}
		if (n >= sizeof(word) * 4)
		{
			word = (uc | (uc << 8) | (uc << 16) | (uc << 24));
			word |= (word << 32);
			ft_memset_fast(&dst, word, n);
			n %= sizeof(word);
		}
		while (n-- > 0)
			*dst++ = uc;
	}
	return (dst0);
}
