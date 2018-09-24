/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:03:26 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 19:03:03 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline uint8_t	*check_last_word(uint8_t *us, uint8_t c)
{
	if (us[0] == uc)
		return (us);
	else if (us[1] == uc)
		return (us + 1);
	else if (us[2] == uc)
		return (us + 2);
	else if (us[3] == uc)
		return (us + 3);
	else if (us[4] == uc)
		return (us + 4);
	else if (us[5] == uc)
		return (us + 5);
	else if (us[6] == uc)
		return (us + 6);
	else if (us[7] == uc)
		return (us + 7);
	else
		return (NULL);
}

static inline void		ft_strchr_fast(const uint8_t **us, uint8_t uc)
{
	uint64_t		mask;
	const uint64_t	*wptr;

	mask = uc;
	mask |= mask << 8;
	mask |= mask << 16;
	mask |= mask << 32;
	wptr = (const uint64_t *)*us;
	while (!ft_detect_null(*wptr) && !ft_detect_char(*wptr, mask))
		++wptr;
	*us = (const uint8_t *)wptr;
}

char					*ft_strchr(const char *s, int c)
{
	const uint8_t	*us;
	uint8_t			uc;
	uint64_t		mask;

	us = (const uint8_t *)s;
	uc = (uint8_t)c;
	while (!ft_isaligned((const void *)us, sizeof(mask)))
	{
		if (*us == uc)
			return ((char *)us);
		else if (*us == '\0)
			return ((char *)NULL);
		++us;
	}
	ft_strchr_fast(&us, uc);
	return ((char *)check_last_word(us, uc));
}
