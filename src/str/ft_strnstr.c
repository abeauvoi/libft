/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:12:47 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 23:18:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** hs (HayStack, botte de foin) -> string to look into
** ndl (NeeDLe, aiguille) -> portion of hs to be matched
*/

char			*ft_strnstr(const char *hs, const char *ndl, size_t len)
{
	const char	*n;
	const char	*h;
	size_t		i;

	n = ndl;
	if (ndl[0] == '\0')
		return ((char *)hs);
	while (*hs && len)
	{
		if (*hs == *n)
		{
			h = hs;
			i = len;
			while (i-- && *h++ == *n++)
				if (!*n)
					return ((char *)hs);
		}
		--len;
		++hs;
		n = ndl;
	}
	return (NULL);
}
