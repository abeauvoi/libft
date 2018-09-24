/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:57:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 06:40:27 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlen(const char *str)
{
	const char			*cp;
	unsigned long int	*wptr;
	unsigned long int	word;

	cp = str;
	while (!ft_isaligned((const void *)cp, sizeof(lword)))
	{
		if (*cp == '\0')
			return (cp - str);
		++cp;
	}
	wptr = (unsigned long int *)cp;
	return ((size_t)(cp - str));
}
