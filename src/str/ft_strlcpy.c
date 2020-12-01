/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 02:20:51 by mac               #+#    #+#             */
/*   Updated: 2020/11/29 02:23:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t 	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	const size_t	srclen = ft_strlen(src);

	if (srclen + 1 < maxlen)
		ft_memcpy(dst, src, srclen + 1);
	else if (maxlen != 0)
	{
		memcpy(dst, src, maxlen - 1);
		dst[maxlen - 1] = '\0';
	}
	return srclen;

}
