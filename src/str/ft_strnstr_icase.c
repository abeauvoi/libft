/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_icase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:37:57 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/24 16:11:05 by abeauvoi         ###   ########.fr       */
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
		if (ft_to_upper(*hs) == ft_to_upper(*n))
		{
			h = hs;
			i = len;
			while (i-- && ft_to_upper(*(h++)) == ft_to_upper(*(n++)))
				if (!*n)
					return ((char *)hs);
		}
		--len;
		++hs;
		n = ndl;
	}
	return (NULL);
}
