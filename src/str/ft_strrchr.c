/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:10:08 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/04 00:44:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define	LONGWORD 0
#define	END_MASK 1
#define	LAST_BYTE_ADDR 2 
#define	GOAL_MAGNET 3

char					*ft_strrchr(const char *str, int c)
{
	const uint64_t 	*last_word_addr = (const uint64_t *)((uintptr_t)str & -8);
	const uint64_t	*longptr;
	uint64_t		vars[4];
	char 			*result;
	const uint64_t 	goal = (~0ULL / 255) * (char)c;

	vars[LAST_BYTE_ADDR] = (uint64_t)(str + ft_strlen(str) - 1);
	longptr = (const uint64_t *)(vars[LAST_BYTE_ADDR] & -8);
	vars[END_MASK] = (0XFFFFFFFFFFFFFF00ULL &
			(-256ULL << ((vars[LAST_BYTE_ADDR] - (uint64_t)longptr) << 3))),
	vars[LONGWORD] = (*longptr | vars[END_MASK]) ^ (goal & vars[END_MASK]);
	while ((vars[GOAL_MAGNET] = ft_haschar(vars[LONGWORD], goal)) == 0)
	{
		if (longptr == last_word_addr)
			return (NULL);
		vars[LONGWORD] = *--longptr;
	}
	result = (char *)longptr + 7 -  (__builtin_clzll(vars[GOAL_MAGNET]) >> 3);
	return (result >= str ? result : NULL);
}

#ifdef DEBUG
#include <string.h>

int				main(int ac, char *av[])
{
	if (ac == 3) {
		char 	*str = av[1];
		char 	c = av[2][0];
		printf("[str:%s][ft_strrchr:%s][strrchr:%s]\n", str, ft_strrchr(str, c), strrchr(str, c));
	}
	return 0;
}
#endif
