/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:35:35 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/26 15:10:39 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	unsigned int	i;

	if ((new = (char *)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		++i;
	}
	new[i] = s[i];
	return (new);
}

char				*ft_strmap2(char const *s, char (*f)(char), size_t n)
{
	char			*new;
	char			*tmp;

	if ((new = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	tmp = new;
	while (*s)
		*tmp++ = f(*s++);
	return (new);
}
