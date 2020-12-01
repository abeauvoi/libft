/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:37:12 by mac               #+#    #+#             */
/*   Updated: 2020/11/30 17:04:34 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char 	*ft_itoa(int n)
{
	char			*buf;
	unsigned int 	un;
	unsigned char	next;

	un = (unsigned int)(n < 0 ? -n : n);
	next = (unsigned char)ft_nbrlen_b10((uint64_t)un) + (n < 0);
	buf = malloc(next + 1);
	if (buf == NULL)
		return (NULL);
	buf[next] = '\0';
	if (n < 0)
		buf[0] = '-';
	while (un >= 10U)
	{
		buf[--next] = (un % 10U) + '0';
		un /= 10U;
	}
	if (un < 10U)
		buf[--next] = un + '0';
	return (buf);
}
