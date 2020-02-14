/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_icase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:37:57 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/14 15:32:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** hs (HayStack, botte de foin) -> string to look into
** ndl (NeeDLe, aiguille) -> portion of hs to be matched
*/

char		*ft_strnstr_icase(const char *hs, const char *ndl, size_t len)
{
	const char	*n;
	const char	*h;
	size_t		i;

	n = ndl;
	if (ndl[0] == '\0')
		return ((char *)hs);
	while (*hs && len)
	{
		if (ft_toupper(*hs) == ft_toupper(*n))
		{
			h = hs;
			i = len;
			while (i-- && ft_toupper(*(h++)) == ft_toupper(*(n++)))
				if (!*n)
					return ((char *)hs);
		}
		--len;
		++hs;
		n = ndl;
	}
	return (NULL);
}
