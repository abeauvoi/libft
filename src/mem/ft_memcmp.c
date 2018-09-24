/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 20:59:14 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_memcmp_fast(const uint8_t **us1, const uint8_t **us2,
		size_t n)
{
	const uint64_t	*ws1;
	const uint64_t	*ws2;

	ws1 = (const uint64_t *)*us1;
	ws2 = (const uint64_t *)*us2;
	while (n >= sizeof(uint64_t) && *ws1 == *ws2)
	{
		++ws1;
		++ws2;
		n -= sizeof(uint64_t);
	}
	*us1 = ws1;
	*us2 = ws2;
}

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const uint8_t	*us1;
	const uint8_t	*us2;

	us1 = (const uint8_t *)s1;
	us2 = (const uint8_t *)s2;
	if (n)
	{
		if (ft_isaligned(us1, sizeof(uint64_t))
				&& ft_isaligned(us2, sizeof(uint64_t)))
		{
			ft_memcmp_fast(&us1, &us2, n);
			n %= sizeof(uint64_t);
		}
		while (n-- > 0 && *us1 == *us2)
		{
			++us1;
			++us2;
		}
	}
	return (n ? (int)(*us1 - *us2) : 0);
}
