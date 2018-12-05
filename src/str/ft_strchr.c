/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:03:26 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 23:54:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ZERO_MAGNET 0
#define GOAL_MAGNET 1
#define GOAL_CTZ 2
#define ZERO_CTZ 3
#define BEFORE_MASK 4

/*
** goal is 8 copies of 'c'.
**
** p is a pointer aligned downwards on an 8-byte boundary.
**
** The first longword is masked in order to neither match '\0' or c.
** We ensure that by shifting each byte of BEFORE_MASK to the right by one,
** when AND'ing it with 'goal'.
** Every high bit of each byte of BEFORE_MASK is set to 0 and the rest to 1.
** It means every byte before str[0] isn't the strict opposite of each byte
** in 'goal'.
** This will prevent the loop from failing on the first iteration of
** ft_haschar() (ft_haschar would do : longword ^ goal, which would trigger
** the detection of a zero byte).
*/

char 				*ft_strchr(const char *str, int c)
{
	const uint64_t 	*p;
	uint64_t 		v[5];
	uint64_t 		longword;
	const uint64_t 	goal = (~0ULL / 255) * (uint8_t)c; 

	v[BEFORE_MASK] = (1ULL << ((uintptr_t)str << 3)) - 1;
	p = (const uint64_t *)((uintptr_t)str & -8);
	longword = (*p | v[BEFORE_MASK])
		^ (goal & ft_bytewise_shr((uint8_t *)&v[BEFORE_MASK], 1));
	while (1)
	{
		v[ZERO_MAGNET] = ft_haszero(longword);
		v[GOAL_MAGNET] = ft_haschar(longword, goal);
		if ((v[ZERO_MAGNET] | v[GOAL_MAGNET]) != 0)
			break ;
		longword = *++p;
	}
	v[ZERO_CTZ] = __builtin_ctzll(v[ZERO_MAGNET]);
	v[GOAL_CTZ] = __builtin_ctzll(v[GOAL_MAGNET]);
	return (v[GOAL_CTZ] <= v[ZERO_CTZ] || v[ZERO_CTZ] == 0ULL ?
			((char *)p) + (v[GOAL_CTZ] >> 3) : NULL);
}
