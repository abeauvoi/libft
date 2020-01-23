/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_callback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:04:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 14:57:17 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_callback(const char *s, bool (*callback)(uint8_t))
{
	const uint8_t	*us;
	uint8_t			uc;

	us = (const uint8_t *)s;
	while (1)
	{
		uc = *us;
		if (callback(uc))
			return ((char *)us);
		else if (uc == '\0')
			return ((char *)NULL);
		++us;
	}
	__builtin_unreachable();
}
