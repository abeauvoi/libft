/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:10:08 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/14 15:42:51 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *str0, int c)
{
	char  *str;

	str = (char *)str0;
	str += ft_strlen(str0) - 1;
	while (str != str0)
	{
		if (*str == c)
			return (str);
		--str;
	}
	return (NULL);
}
