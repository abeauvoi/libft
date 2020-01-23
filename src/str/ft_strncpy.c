/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:52:48 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:33:14 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst0, const char *src0, size_t n)
{
	char			*dst;
	const uint64_t	*asrc;
	uint64_t		*adst;
	size_t			n2;

	dst = dst0;
	if (n >= sizeof(uint64_t)
			&& ft_isaligned((const void *)src0, sizeof(void *))
			&& ft_isaligned((const void *)dst0, sizeof(void *)))
	{
		n2 = (n >> 3);
		asrc = (const uint64_t *)src0;
		adst = (uint64_t *)dst0;
		while (n2-- > 0 && !ft_detect_null(*asrc))
			*adst++ = *asrc++;
		src0 = (const char *)asrc;
		dst = (char *)adst;
	}
	while (n-- > 0 && *src0 != '\0')
		*dst++ = *src0++;
	while (n-- > 0)
		*dst++ = '\0';
	return (dst0);
}
