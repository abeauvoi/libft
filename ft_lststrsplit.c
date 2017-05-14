/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:45:08 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/10 19:24:02 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_len(const char *s, char c)
{
	return (*s && *s != c ? ft_word_len(++s, c) + 1 : 0);
}

t_list			*ft_lststrsplit(const char *s, char c)
{
	t_list		*lst;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		ft_lstpush(&lst,
				ft_lstnew((void *)ft_strsub(s, i, ft_word_len(s + i, c)),
					ft_word_len(s + i, c), FT_LSTNEW_CPY));
		while (s[i] && s[i] != c)
			++i;
	}
	return (lst);
}
