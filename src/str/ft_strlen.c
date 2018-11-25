/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:57:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/25 16:43:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlen(const char *str)
{
	const uintptr_t	str_int = (uintptr_t)str;
	const uint64_t	*p;
	uint64_t 		lword;
	uint64_t 		res;

	if (str[0] == '\0')
		return (0);
	p = (const uint64_t *)(str_int & -8);
	lword = *p | ((1ULL << (str_int << 3)) - 1);
	while ((res = ft_haszero(lword)) == 0)
		lword = *(++p);
	return (((const char *)p) + (__builtin_ctzll(res) >> 3) - str);
}
