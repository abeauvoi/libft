/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_b10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 06:50:42 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/18 17:37:05 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		ft_nbrlen_b10(uint64_t val)
{
	if (val < 10)
		return (1);
	if (val < 100)
		return (2);
	if (val < 1000)
		return (3);
	if (val < 1000000000000ull)
	{
		if (val < 100000000)
		{
			if (val < 1000000)
			{
				if (val < 10000)
					return (4);
				return (5 + (val >= 100000));
			}
			return (7 + (val >= 10000000));
		}
		if (val < 10000000000ull)
			return (9 + (val >= 1000000000));
		return (11 + (val >= 100000000000ull));
	}
	return (12 + ft_nbrlen_b10(val / 1000000000000ull));
}
