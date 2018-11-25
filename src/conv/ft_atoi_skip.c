/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:43:55 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/18 18:22:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline uint32_t inner_loop(const char *cp)
{
	uint32_t	acc;
	uint8_t		digit;

	acc = 0;
	while ((digit = ft_todigit(*cp++)) < 9)
	{
		if (acc > 214748364)
			return (-1U);
		else
		{
			acc *= 10;
			if (INT_MAX - digit < acc)
				return (-1U);
			else
				acc += digit;
		}
	}
	return (acc);
}

int					ft_atoi_skip(const char **s)
{
	const char	*cp;
	uint8_t		sign;
	uint32_t 	acc;

	cp = *s;
	while (ft_isspace(*cp++))
		continue ;
	if (*cp == '-' || *cp == '+')
		sign = *cp++;
	acc = inner_loop(cp); 
	*s = cp;
	return (sign == '-' ? -(int)acc : acc);
}
