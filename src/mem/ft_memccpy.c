/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:30:32 by mac               #+#    #+#             */
/*   Updated: 2020/11/28 23:07:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const uint8_t 	*src2;
	uint8_t			*dest2;
	uint8_t			c2;

	src2 = (const uint8_t *)src;
	dest2 = (uint8_t *)dest;
	c2 = (uint8_t)c;
	while (n-- > 0)
	{
		dest2[0] = src2[0];
		++dest2;
		if (src2[0] == c2)
			return ((void *)dest2);
		++src2;
	}
	return (NULL);
}
