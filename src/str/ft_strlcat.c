/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:20:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 23:04:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		dlen;

	if ((dlen = ft_strlen(dst)) >= n)
		return (ft_strlen(src) + n);
	dst += dlen;
	n -= dlen - 1;
	i = 0;
	while (i < n && (dst[i] = src[i]) != '\0')
		if (++i == n)
			src[i] = '\0';
	return (dlen + ft_strlen(src));
}
