/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:57:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/25 18:57:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t n)
{
	uint8_t			*out;
	const uint8_t	*in;
	int 			inc;
	bool			cond;

	if (n == 0)
		return (dst);
	if ((const char *)src >= (char *)dst + n
			|| (char *)dst >= (const char *)src + n)
		return (ft_memcpy(dst, src, n));
	else
	{
		cond = (src < dst);
		in = (cond ? (const uint8_t *)src + n - 1 : (const uint8_t *)src);
		out = (cond ? (uint8_t *)dst + n - 1 : (uint8_t *)dst);
		inc = (cond ? -1 : 1);
		*out = *in;
		while (--n > 0)
		{
			in += inc;
			out += inc;
			*out = *in;
		}
		return (dst);
	}
}
