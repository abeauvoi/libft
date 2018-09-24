/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:31:02 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 08:07:46 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_pow(int value,
		unsigned int exponent)
{
	uintmax_t	result;

	if (exponent == 0)
		return (1);
	result = 1;
	while (exponent-- > 0)
		result *= value;
	return (result);
}
