/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 06:50:42 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/05/23 06:52:17 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

/*
** Returns the length of the string representation of n
** @param n -> the value that needs counting
*/

t_u8		ft_numstrlen(t_u64 n)
{
	t_u8	l;

	l = !n;
	while (n)
	{
		n /= 10;
		++l;
	}
	return (l);
}
