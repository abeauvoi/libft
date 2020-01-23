/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:57:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/01 19:21:55 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	find_zero_byte(const char *str0, const char *str)
{
	if (str[0] == '\0')
		return (str - str0);
	else if (str[1] == '\0')
		return (&str[1] - str0);
	else if (str[2] == '\0')
		return (&str[2] - str0);
	else if (str[3] == '\0')
		return (&str[3] - str0);
	else if (str[4] == '\0')
		return (&str[4] - str0);
	else if (str[5] == '\0')
		return (&str[5] - str0);
	else if (str[6] == '\0')
		return (&str[6] - str0);
	else
		return (&str[7] - str0);
}

size_t					ft_strlen(const char *str0)
{
	const uint64_t	*lwptr;
	const uintptr_t	s_int = (uintptr_t)str0;
	uint64_t		lword;

	lwptr = (const uint64_t *)(s_int & -8);
	lword = *lwptr | ((1ULL << (s_int << 3)) - 1);
	while (!ft_detect_null(lword))
		lword = *++lwptr;
	return (find_zero_byte(str0, (const char *)lwptr));
}
