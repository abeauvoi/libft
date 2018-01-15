/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:31:53 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/01/10 23:54:32 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	digit_value(char c)
{
	return ((unsigned int)(c - '0'));
}

int					ft_atoi(const char *s)
{
	t_bool			neg;
	unsigned int	acc;
	unsigned int	d;

	acc = 0;
	neg = FALSE;
	while (ft_isspace(*s))
		++s;
	if (*s == '-')
	{
		neg = TRUE;
		++s;
	}
	else if (*s == '+')
		++s;
	acc = digit_value(*s);
	while ((d = digit_value(*++s)) <= 9)
		acc = acc * 10 + d;
	if (neg)
		acc = ~acc + 1;
	return ((int)acc);
}
