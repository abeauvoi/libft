/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:57:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/11/18 18:19:06 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

static size_t	find_null(const char *s, const char *str)
{
	if (!s[0])
		return (s - str);
	if (!s[1])
		return (s - str + 1);
	if (!s[2])
		return (s - str + 2);
	if (!s[3])
		return (s - str + 3);
	if (!s[4])
		return (s - str + 4);
	if (!s[5])
		return (s - str + 5);
	if (!s[6])
		return (s - str + 6);
	return (s - str + 7);
}

static void		init(uintptr_t str, long *va, long *vb,
		const unsigned long **ls)
{
	*ls = (const unsigned long *)(str & ~LONGPTR_MASK);
	*va = (**ls - MASK01);
	*vb = ((~**ls) & MASK80);
	++*ls;
}

size_t			ft_strlen(const char *str)
{
	const char			*s;
	const unsigned long	*ls;
	long 				va;
	long				vb;

	init((uintptr_t)str, &va, &vb, &ls);
	s = str;
	if (va & vb)
		while (s < (const char *)ls)
		{
			if (*s == 0)
				return (s - str);
			++s;
		}
	while (1)
	{
		va = (*ls - MASK01);
		vb = ((~*ls) & MASK80);
		if (va & vb)
			return (find_null(s = (const char *)ls, str));
		++ls;
	}
	return (0);
}
