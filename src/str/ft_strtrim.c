/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:24:05 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/30 16:13:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_is_in_set(char c, const char *set)
{
	while (*set != '\0' && *set != c)
		++set;
	return (*set == c);
}

char			*ft_strtrim(const char *s, const char *set)
{
	char		*trim;
	const char	*end;
	size_t		len;

	while (*s != '\0' && ft_is_in_set(*s, set))
		++s;
	if (*s == '\0')
		return (ft_strnew(0));
	end = s + ft_strlen(s);
	while (end > s && ft_is_in_set(end[-1], set))
		--end;
	len = end - s;
	trim = malloc(len + 1);
	if (trim == NULL)
		return (NULL);
	trim[len] = '\0';
	return (ft_strncpy(trim, s, len));
}
