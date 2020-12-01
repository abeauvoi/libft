/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/29 01:42:18 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *p1, const void *p2, size_t n)
{
	const uint8_t	*u8p1;
	const uint8_t	*u8p2;

	u8p1 = (const uint8_t *)p1;
	u8p2 = (const uint8_t *)p2;
	while (n-- > 0)
	{
		if (*u8p1 != *u8p2)
			return (*u8p1 - *u8p2);
		++u8p1;
		++u8p2;
	}
	return (0);
}
