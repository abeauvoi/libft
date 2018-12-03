/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:57:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/03 23:43:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlen(const char *str)
{
	const uint64_t	*longptr;
	uint64_t 		longword;
	uint64_t 		zero_magnet;

	if (str[0] == '\0')
		return (0);
	longptr = (const uint64_t *)((uint64_t)str & -8);
	longword = *longptr | ((1ULL << ((uint64_t)str << 3)) - 1);
	while ((zero_magnet = ft_haszero(longword)) == 0)
		longword = *++longptr;
	return (((const char *)longptr)
			+ (__builtin_ctzll(zero_magnet) >> 3) - str);
}
