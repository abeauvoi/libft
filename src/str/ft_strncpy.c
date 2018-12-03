/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:52:48 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/01 16:44:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char 			*orig_dst;
	const uint64_t	*ullsrc;
	uint64_t 		*ulldst;

	orig_dst = dst;
	if (len > 7 && ((uintptr_t)src & 7) == 0
			&& ((uintptr_t)dst & 7) == 0)
	{
		ullsrc = (const uint64_t *)src;
		ulldst = (uint64_t *)src;
		while (len > 7 && ft_haszero(*ullsrc) == 0)
		{
			len -= 8;
			*ulldst++ = *ullsrc++;
		}
		src = (const char *)ullsrc;
		dst = (char *)ulldst;
	}
	while (len-- > 0)
	{
		*dst++ = *src;
		if (*src != '\0')
			++src;
	}
	return (orig_dst);
}
