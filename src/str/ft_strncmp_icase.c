/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_icase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:45:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/14 15:30:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp_icase(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0 && ft_tolower(*s1) == ft_tolower(*s2))
	{
		if (n == 0 || *s1 == '\0')
			return (0);
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}
