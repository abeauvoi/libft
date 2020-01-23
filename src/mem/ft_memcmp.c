/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/25 17:57:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *p1, const void *p2, size_t n)
{
	const uint8_t	*ucp1;
	const uint8_t	*ucp2;
	const uint64_t	*ullp1;
	const uint64_t	*ullp2;

	if (n == 0)
		return (0);
	ucp1 = (const uint8_t *)p1;
	ucp2 = (const uint8_t *)p2;
	if (n > 7 && ((uintptr_t)p1 & 7) == 0 && ((uintptr_t)p2 & 7) == 0)
	{
		ullp1 = (const uint64_t *)*ucp1;
		ullp2 = (const uint64_t *)*ucp2;
		while (*ullp1++ == *ullp2++ && (n -= 8) > 7)
			continue ;
		ucp1 = (const uint8_t *)ullp1;
		ucp2 = (const uint8_t *)ullp2;
	}
	while (n-- > 0 && *ucp1++ == *ucp2++)
		continue ;	
	return (n != 0 ? (int)(*ucp1 - *ucp2) : 0);
}
