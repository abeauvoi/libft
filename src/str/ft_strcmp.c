/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:41:24 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 21:00:26 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const uint8_t	*us1;
	const uint8_t	*us2;
	const uint64_t	*ws1;
	const uint64_t	*ws2;

	us1 = (const uint8_t *)s1;
	us2 = (const uint8_t *)s2;
	if (ft_isaligned((const void *)us1, sizeof(ws1))
			&& ft_isaligned((const void *)us2, sizeof(ws1)))
	{
		ws1 = (const uint64_t*)us1;
		ws2 = (const uint64_t*)us2;
		while (!ft_detect_null(*ws1) && *ws1++ == *ws2++)
			continue ;
		us1 = (const uint8_t*)ws1;
		us2 = (const uint8_t*)ws2;
	}
	while (*us1 != '\0' && *us1++ == *us2++)
		continue ;
	return (*us1 - *us2);
}
