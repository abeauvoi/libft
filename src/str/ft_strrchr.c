/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:10:08 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/29 01:53:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *str0, int c)
{
	const char  *str;
	char		b;

	str = (const char *)str0;
	str += ft_strlen(str0);
	b = (char)c;
	while (str >= str0)
	{
		if (*str == b)
			return ((char *)str);
		--str;
	}
	return (NULL);
}
