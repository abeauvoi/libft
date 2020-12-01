/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:14:16 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/29 03:44:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	join = ft_strnew(len_s1 + ft_strlen(s2));
	if (join == NULL)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy(join + len_s1, s2);
	return (join);
}
