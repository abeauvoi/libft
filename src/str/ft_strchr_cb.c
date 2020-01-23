/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_cb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:04:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/01/23 20:22:11 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_cb(const char *s, bool (*cb)(uint8_t))
{
	const uint8_t	*us;
	uint8_t			uc;

	us = (const uint8_t *)s;
	while (1)
	{
		if (cb(*us))
			return ((char *)us);
		else if (uc == '\0')
			return ((char *)NULL);
		++us;
	}
	__builtin_unreachable();
}
