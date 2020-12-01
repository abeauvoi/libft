/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:46:59 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/12/01 21:44:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_word_len(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		++i;
	return (i);
}

static	size_t	ft_word_count(const char *s, char c)
{
	size_t		words;

	words = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == c || s[1] == '\0'))
			++words;
		++s;
	}
	return (words);
}

static void		free_split(char **tab, int last)
{
	while (last-- > 0)
		free(tab[last]);
	free(tab);
}

static void		*init_variables(size_t *i, size_t *j, char ***split,
		size_t words)
{
	*i = 0;
	*j = 0;
	*split = (char **)malloc(sizeof(**split) * (words + 1));
	if (*split == NULL)
		return (NULL);
	(*split)[words] = NULL;
	return ((void *)1);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		i;
	size_t		j;
	size_t		words;

	words = ft_word_count(s, c);
	if (init_variables(&i, &j, &split, words) == NULL)
		return (NULL);
	while (j < words)
	{
		while (s[i] != '\0' && s[i] == c)
			++i;
		split[j++] = ft_substr(s, i, ft_word_len(s + i, c));
		if (split == NULL)
		{
			free_split(split, j);
			return (NULL);
		}
		while (s[i] != '\0' && s[i] != c)
			++i;
	}
	return (split);
}
