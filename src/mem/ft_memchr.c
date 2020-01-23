/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:45:44 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/01/23 20:31:27 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MASK 0
#define WORD 1
#define CHAR_POS 2
#define GOAL 3

void					*ft_memchr(const void *s, int c, size_t n)
{
	const uint64_t 	*last_word;
	const uint64_t 	*p;
	const char		*last_byte;
	uint64_t 		tab[4];
	char 			*ret;

	if (n == 0)
		return (NULL);
	p = (const uint64_t *)((uintptr_t)s & -8);
	tab[GOAL] = 0x0101010101010101ULL * (uint8_t)c;
	tab[MASK] = ((1ULL << ((uintptr_t)s << 3)) - 1);
	tab[WORD] = (*p | tab[MASK]) ^ (tab[GOAL] & tab[MASK]);
	last_byte = (const char *)s + n - 1;
	last_word = (const uint64_t *)((uintptr_t)last_byte & -8);
	while ((tab[CHAR_POS] = ft_haschar(tab[WORD], tab[GOAL])) == 0)
	{
		if (p == last_word)
			return (NULL);
		tab[WORD] = *(++p);
	}
	ret = (char *)p + (__builtin_ctzll(tab[CHAR_POS]) >> 3);
	return (ret <= last_byte ? ret : NULL);
}
