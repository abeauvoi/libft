/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:45:44 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/01 21:33:38 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void		ft_memchr_fast(uint8_t **us, size_t n, int c)
{
	uint64_t		goal;
	const uint64_t	*lwptr;
	uint64_t		count;
	uint64_t		lword;

	goal = 0x0101010101010101ULL * (uint8_t)c;
	lwptr = (const uint64_t *)*us;
	count = n >> 3;
	lword = *lwptr;
	while (!ft_detect_null(lword)
			&& !ft_detect_char(lword, goal)
			&& --count > 0)
		lword = *++lwptr;
	*us = (const uint8_t *)lwptr;
}

void					*ft_memchr(const void *s, int c, size_t n)
{
	const uint8_t	*us;
	uint8_t			uc;

	if (n > 0)
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
