/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:34:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 21:04:30 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_macros.h"

char		*ft_strcpy(char *dst0, const char *src0)
{
	const uint8_t	*src;
	uint8_t			*dst;
	const uint64_t	*ulong_src;
	uint64_t		*ulong_dst;

	src = src0;
	dst = dst0;
	if (ft_isaligned((const void *)src, sizeof(ulong_src))
			&& ft_isaligned((const void *)dst, sizeof(ulong_dst)))
	{
		ulong_src = (const uint64_t *)src;
		ulong_dst = (uint64_t *)dst;
		while (!ft_detect_null(*ulong_src))
			*ulong_dst++ = *ulong_src++;
		src = (const uint8_t *)ulong_src;
		dst = (uint8_t *)ulong_dst;
	}
	while ((*dst++ = *src++) != '\0')
		continue ;
	return (dst0);
}
