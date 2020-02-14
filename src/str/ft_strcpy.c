/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:34:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:59:36 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	char	 		*dst0;
	const uint64_t	*u64src;
	uint64_t		*u64dst;

	dst0 = dst;
	if (((uintptr_t)src & 7) == 0 && ((uintptr_t)dst & 7) == 0)
	{
		u64src = (const uint64_t *)src;
		u64dst = (uint64_t *)dst;
		while (ft_haszero(*u64src) == 0)
			*u64dst++ = *u64src++;
		src = (const char *)u64src;
		dst = (char *)u64dst;
	}
	while ((*dst++ = *src++) != '\0')
		continue ;
	return (dst0);
}
