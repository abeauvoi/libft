/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:09:14 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/24 15:09:21 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin2(char const *s1, char const *s2, size_t len_s1,
		size_t len_s2)
{
	char	*join;

	if ((join = (char *)malloc(len_s1 + len_s2 + 1)) == NULL)
		return (NULL);
	return (ft_strcpy(ft_strcpy(join, s1) + len_s1, s2));
}
