/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:34:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:53:48 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_macros.h"

char		*ft_strcpy(char *dst0, const char *src0)
{
	const uint8_t	*src;
	uint8_t			*dst;
	const uint64_t	*lwsrc;
	uint64_t		*lwdst;

	src = src0;
	dst = dst0;
	if (ft_isaligned((const void *)src, sizeof(void *))
			&& ft_isaligned((const void *)dst, sizeof(void *)))
	{
		lwsrc = (const uint64_t *)src;
		lwdst = (uint64_t *)dst;
		while (!ft_detect_null(*lwsrc))
			*lwdst++ = *lwsrc++;
		src = (const uint8_t *)lwsrc;
		dst = (uint8_t *)lwdst;
	}
	while ((*dst++ = *src++) != '\0')
		continue ;
	return (dst0);
}
