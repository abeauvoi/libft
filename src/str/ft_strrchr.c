/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:10:08 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 22:05:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *str, int c)
{
	const uint8_t 	*p;
	uint8_t			uc;	

	p = (const uint8_t *)(str + ft_strlen(str) - 1);
	uc = (uint8_t)c;
	while (p > str)
	{
		if (*p == uc)
			return (p);
		--p;
	}
	return (NULL);
}
