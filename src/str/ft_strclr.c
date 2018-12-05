/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:23:13 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 22:33:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	uint64_t		*p;
	uint64_t		longword;
	uint64_t		zero_match;

	p = (uint64_t *)((uint64_t)s & -8);
	longword = (*p | (1ULL << ((uint64_t)s << 3)) - 1);
	while ((zero_match = ft_haszero(longword)) == 0)
	{
		*p = 0ULL;
		longword = *++p;
	}
	s = (char *)p;
	while (*s != '\0')
		*s++ = 0;
}
