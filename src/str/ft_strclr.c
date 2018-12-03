/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:23:13 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/02 02:27:14 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	uint64_t		*p;
	uint64_t		lword;
	uint64_t		zero_match;

	p = (uint64_t)s & -8;
	lword = (*p | (1ULL << ((uint64_t)s << 3)) - 1);
	while ((zero_match = ft_haszero(lword)) == 0)
		*w++ = (uint64_t)0;
	s = (char *)wptr;
	while (*s != '\0')
		*s++ = 0;
}
