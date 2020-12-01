/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:20:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/30 17:05:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = maxlen;
	while (n-- != 0 && *d != '\0')
		++d;
	dlen = d - dst;
	n = maxlen - dlen;
	if (n == 0)
		return(dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			--n;
		}
		++s;
	}
	*d = '\0';
	return(dlen + (s - src));
}
