/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_icase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:37:57 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/15 19:45:31 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_types.h"

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
		if (TO_UPPER(*hs) == TO_UPPER(*n))
		{
			h = hs;
			i = len;
			while (i-- && TO_UPPER(*(h++)) == TO_UPPER(*(n++)))
				if (!*n)
					return ((char *)hs);
		}
		--len;
		++hs;
		n = ndl;
	}
	return (NULL);
}
