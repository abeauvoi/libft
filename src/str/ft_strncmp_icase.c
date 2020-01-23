/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_icase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:45:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 23:17:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp_icase(const char *s1, const char *s2, size_t n)
{
	const uint8_t	*us1;
	const uint8_t	*us2;

	while (n-- > 0 && ft_tolower(*us1) == ft_tolower(*us2))
	{
		if (n == 0 || *us1 == '\0')
			return (0);
		++us1;
		++us2;
	}
	return (*us1 - *us2);
}
