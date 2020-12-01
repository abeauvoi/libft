/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:43:55 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/27 17:26:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t inner_loop(const char *ptr)
{
	uint32_t	acc;
	uint8_t		digit;

	acc = 0;
	while ((digit = ft_todigit(*ptr++)) < 9)
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
	const char	*ptr;
	uint8_t		sign;
	uint32_t 	acc;

	ptr = *s;
	while (ft_isspace(*ptr++))
		continue ;
	sign = '+';
	if (*ptr == '-')
		sign = *ptr++;
	acc = inner_loop(ptr); 
	*s = ptr;
	return (sign == '-' ? -(int)acc : acc);
}
