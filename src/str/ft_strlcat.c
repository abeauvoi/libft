/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:20:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/24 16:02:47 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		dlen;
	uint64_t	*aligned_ptr;

	if ((dlen = ft_strlen(dst)) >= n)
		return (ft_strlen(src) + n);
	if (dlen > sizeof(*aligned_ptr))
	{
		while (*dst != '\0'
				&& !ft_isaligned((const void *)dst, sizeof(uint64_t)))
			++dst;
		aligned_ptr = (uint64_t *)dst;
		while (!ft_detect_null(*aligned_ptr))
			++aligned_ptr;
		dst = (char *)aligned_ptr;
	}
	while (*dst != '\0')
		++dst;
	n -= dlen - 1;
	i = 0;
	while (i < n && (dst[i] = src[i]) != '\0')
		if (++i == n)
			src[i] = '\0';
	return (dlen + ft_strlen(src));
}
