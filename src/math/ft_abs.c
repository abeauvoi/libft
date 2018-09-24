/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:49:54 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 07:58:42 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline intmax_t		ft_abs(intmax_t value)
{
	const intmax_t	mask = (value >> (sizeof(value) * 8 - 1));

	return ((value ^ mask) - mask);
}
