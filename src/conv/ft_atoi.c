/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:31:53 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/29 02:14:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_atoi(const char *s)
{
	char		sign;
	uint64_t	acc;
	uint8_t		digit;

	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		sign = *s++;
	acc = 0;
	while ((digit = ft_digittoint(*s++)) <= 9)
	{
		acc *= 10;
		acc += digit;
	}
	return (sign == '-' ? -(int)acc : acc);
}
