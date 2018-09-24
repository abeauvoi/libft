/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:31:53 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/18 17:46:06 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	char		sign;
	uint32_t	acc;
	uint8_t		digit;

	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		sign = *s++;
	acc = 0;
	while ((digit = ft_todigit(*s++)) <= 9)
	{
		if (acc > INT_MAX / 10)
			return (-1);
		else
		{
			acc *= 10;
			if (INT_MAX - digit < acc)
				return (-1);
			else
				acc += digit;
		}
	}
	return (sign == '-' ? -(int)acc : acc);
}
