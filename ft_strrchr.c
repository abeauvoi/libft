/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:10:08 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/04/19 18:26:31 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strrchr(const char *s, int c)
{
	const unsigned char	*end;

	end = (const unsigned char *)s;
	end += ft_strlen(s);
	while (end != (const unsigned char *)s)
	{
		if (*end == (unsigned char)c)
			return ((char *)end);
		--end;
	}
	return (*end == (unsigned char)c ? (char *)end : NULL);
}
