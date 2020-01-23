/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:20:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:53:05 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dlen;
	size_t	len;
	size_t	res;

	dlen = ft_strlen(dst);
	len = ft_strlen(src);
	res = dlen + len;
	if (dlen >= n)
		return (len + n);
	dst += dlen;
	n -= dlen;
	if (len >= n)
		len = n - 1;
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (res);
}
