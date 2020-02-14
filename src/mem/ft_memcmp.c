/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:49:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *p1, const void *p2, size_t n)
{
	const uint8_t	*u8p1;
	const uint8_t	*u8p2;
	const uint64_t	*u64p1;
	const uint64_t	*u64p2;

	if (n == 0)
		return (0);
	u8p1 = (const uint8_t *)p1;
	u8p2 = (const uint8_t *)p2;
	if (n > 7 && ((uintptr_t)p1 & 7) == 0 && ((uintptr_t)p2 & 7) == 0)
	{
		u64p1 = (const uint64_t *)u8p1;
		u64p2 = (const uint64_t *)u8p2;
		while (*u64p1++ == *u64p2++ && (n -= 8) > 7)
			continue ;
		u8p1 = (const uint8_t *)u64p1;
		u8p2 = (const uint8_t *)u64p2;
	}
	while (n-- > 0 && *u8p1++ == *u8p2++)
		continue ;	
	return (n != 0 ? (int)(*u8p1 - *u8p2) : 0);
}
