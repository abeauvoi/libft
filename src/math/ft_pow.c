/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:31:02 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:46:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_pow(int value, unsigned int exponent)
{
	uint64_t	result;

	if (exponent == 0)
		return (1);
	result = 1;
	while (exponent-- > 0)
		result *= value;
	return (result);
}
