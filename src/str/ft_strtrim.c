/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:24:05 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 22:38:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strtrim(const char *s)
{
	char		*trim;
	const char	*end;
	size_t		len;

	end = s + ft_strlen(s) - 1;
	while (*s != '\0' && ft_isblank(*s))
		++s;
	while (ft_isblank(*end))
		--end;
	len = end - s + 2;
	if ((trim = (char *)malloc(len)) == NULL)
		return (NULL);
	return (ft_strncpy(trim, s, len));
}
