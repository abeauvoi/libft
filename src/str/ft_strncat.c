/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:17:20 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/12/01 23:53:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *dst, const char *src, size_t n)
{
	const size_t	dstlen = ft_strlen(dst);

	ft_strncpy(dst + dstlen, src, n);
	dst[dstlen + n + 1] = '\0';
	return (dst);
}
