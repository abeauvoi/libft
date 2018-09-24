/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_callback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:04:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 19:18:39 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_callback(const char *s, bool (*callback)(uint8_t))
{
	const uint8_t	*us;

	us = (const uint8_t *)s;
	while (1)
	{
		if (callback(*us))
			return ((char *)us);
		else if (*us == '\0')
			return ((char *)NULL);
		++us;
	}
	__builtin_unreachable();
}
