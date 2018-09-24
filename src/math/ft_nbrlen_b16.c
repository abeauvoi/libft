/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_b16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:44:40 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/18 17:37:33 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		ft_nbrlen_b16(uint64_t val)
{
	if (val < 0x10)
		return (1);
	if (val < 0x100)
		return (2);
	if (val < 0x1000)
		return (3);
	if (val < 0x1000000000000ull)
	{
		if (val < 0x100000000ull)
		{
			if (val < 0x1000000)
			{
				if (val < 0x10000)
					return (4);
				return (5 + (val >= 0x100000));
			}
			return (7 + (val >= 0x10000000));
		}
		if (val < 0x10000000000ull)
			return (9 + (val >= 0x1000000000));
		return (11 + (val >= 0x100000000000ull));
	}
	return (12 + ft_nbrlen_b16(val / 0x1000000000000ull));
}
