/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:43:39 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/29 01:17:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *dst, int c, size_t n)
{
	uint8_t		*u8dst;
	uint8_t		uc;

	u8dst = (uint8_t *)dst;
	uc = (uint8_t)c;
	while (n-- > 0)
		*u8dst++ = uc;
	return (dst);
}
