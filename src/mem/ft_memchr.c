/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:45:44 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/19 02:54:25 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_memchr_fast(uint8_t **us, size_t n)
{
	uint64_t		mask;
	const uint64_t	*wptr;

	mask = uc;
	mask |= mask << 8;
	mask |= mask << 16;
	mask |= mask << 32;
	wptr = (const uint64_t *)*us;
	while (n >= sizeof(mask)
			&& !ft_detect_null(*wptr)
			&& !ft_detect_char(*wptr, mask))
	{
		n -= sizeof(mask);
		++wptr;
	}
	*us = (const uint8_t *)wptr;
}

void					*ft_memchr(const void *s, int c, size_t n)
{
	const uint8_t	*us;
	uint32_t		uc;

	if (n)
	{
		us = (const uint8_t *)s;
		uc = (uint8_t)c;
		while (!ft_isaligned((const void *)us, sizeof(uint64_t)))
		{
			if (n-- == 0)
				return (*us == uc ? (void *)us : NULL);
			++us;
		}
		ft_memchr_fast(&us, n);
		n %= sizeof(uint64_t);
		while (n-- > 0)
		{
			if (*us == uc)
				return ((void *)us);
			else if (*us == '\0')
				return (NULL);
			++us;
		}
	}
	return (NULL);
}
