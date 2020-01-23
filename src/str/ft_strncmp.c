/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:43:42 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 17:18:06 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_macros.h"
#include "libft_types.h"

static inline void		ft_strncmp_fast(const char **s1, const char **s2,
		size_t n)
{
	const uint64_t		*lws1;
	const uint64_t		*lws2;

	lws1 = (const uint64_t *)*s1;
	lws2 = (const uint64_t *)*s2;
	n >> 3;
	while (n-- > 0
			&& !ft_detect_null(*lws1)
			&& *lws1++ == *lws2++)
		continue ;
	*s1 = (const char *)lws1;
	*s2 = (const char *)lws2;
}

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	uint8_t		c1;
	uint8_t		c2;

	if (n == 0)
		return (0);
	if (n > sizeof(uint64_t)
			&& ft_isaligned((const void *)s1, sizeof(void *))
			&& ft_isaligned((const void *)s2, sizeof(void *)))
	{
		ft_strncmp_fast(&s1, &s2, n);
		n &= sizeof(uint64_t) - 1;	
	}
	while (n > 0)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == 0)
			break;
		--n;
	}
	return (0);
}
