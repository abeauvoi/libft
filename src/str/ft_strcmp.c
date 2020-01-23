/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:41:24 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:58:21 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const uint64_t	*lws1;
	const uint64_t	*lws2;

	if (ft_isaligned((const void *)us1, sizeof(void *))
			&& ft_isaligned((const void *)us2, sizeof(void *)))
	{
		lws1 = (const uint64_t*)s1;
		lws2 = (const uint64_t*)s2;
		while (!ft_detect_null(*lws1) && *lws1++ == *lws2++)
			continue ;
		s1 = (const uint8_t*)lws1;
		s2 = (const uint8_t*)lws2;
	}
	while (*s1 != '\0' && *s1++ == *s2++)
		continue ;
	return (*s1 - *s2);
}
