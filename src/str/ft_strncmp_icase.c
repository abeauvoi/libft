/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_icase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:45:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/18 15:44:32 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_strncmp_icase_fast(const uint8_t **us1,
		const uint8_t **us2,
		size_t n) __attribute__((always_inline))
{
	const uint64_t	*as1;
	const uint64_t	*as2;
	uint64_t		mask;

	mask = 32;
	mask |= (mask << 8);
	mask |= (mask << 16);
	mask |= (mask << 32);
	as1 = (const uint64_t *)*us1;
	as2 = (const uint64_t *)*us2;
	while (n >= sizeof(uint64_t) && (mask | *as1) == (mask | *as2))
	{
		n -= sizeof(uint64_t);
		if (!n || ft_detect_null(*as1) == true)
			return ;
		++as1;
		++as2;
	}
	*us1 = (const uint8_t *)as1;
	*us2 = (const uint8_t *)as2;
}

int					ft_strncmp_icase(const char *s1, const char *s2,
		size_t n)
{
	const uint8_t	*us1;
	const uint8_t	*us2;

	if (!n)
		return (0);
	us1 = (const uint8_t *)s1;
	us2 = (const uint8_t *)s2;
	if (ft_isaligned(s1, sizeof(uint64_t)) == true
			&& ft_isaligned(s2, sizeof(uint64_t)) == true)
	{
		ft_strncmp_icase_fast(&us1, &us2, n);
		n %= sizeof(uint64_t);
	}
	while (n-- > 0 && ft_tolower(*us1) == ft_tolower(*us2))
	{
		if (!n || !*us1)
			return (0);
		++us1;
		++us2;
	}
	return (*us1 - *us2);
}
