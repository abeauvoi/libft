/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:03:26 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/02 02:08:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ZERO_MATCH 0
#define GOAL_MATCH 1
#define GOAL_CTZ 2
#define ZERO_CTZ 3
#define BMASK 4

char 				*ft_strchr(const char *s, int c)
{
	const uint64_t 	*p;
	uint64_t 		v[5];
	uint64_t 		lword;
	const uint64_t 	goal = 0X0101010101010101UL * (uint8_t)c;

	v[BMASK] = (1ULL << ((uintptr_t)s << 3)) - 1;
	p = (const uint64_t *)((uintptr_t)s & -8);
	lword = (*p | v[BMASK]) ^ (goal & ft_insn_shrui((uint8_t *)&v[BMASK], 1));
	while (1)
	{
		v[ZERO_MATCH] = ft_haszero(lword);
		v[GOAL_MATCH] = ft_haschar(lword, goal);
		if ((v[ZERO_MATCH] | v[GOAL_MATCH]) != 0)
			break ;
		lword = *++p;
	}
	v[ZERO_CTZ] = __builtin_ctzll(v[ZERO_MATCH]);
	v[GOAL_CTZ] = __builtin_ctzll(v[GOAL_MATCH]);
	return (v[GOAL_CTZ] <= v[ZERO_CTZ] || v[ZERO_CTZ] == 0ULL ?
			((char *)p) + (v[GOAL_CTZ] >> 3) : NULL);
}
