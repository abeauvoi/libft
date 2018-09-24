/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:43:55 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/18 17:48:16 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi_skip(const char **s)
{
	const char		*cp;
	unsigned int	value;
	char			sign;
	unsigned char	digit;

	cp = *s;
	value = 0;
	while (ft_isspace(*cp++))
		continue ;
	if (*cp == '-' || *cp == '+')
		sign = *cp++;
	while ((digit = ft_todigit(*cp++)) < 9)
	{
		if (value > INT_MAX / 10)
			return (-1);
		else
		{
			value *= 10;
			if (INT_MAX - digit < value)
				return (-1);
			else
				value += digit;
		}
	}
	*s = cp;
	return (sign == '-' ? -(int)value : value);
}
