/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:14:16 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/24 15:09:04 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	if ((join = ft_strnew(len_s1 + ft_strlen(s2))) == NULL)
		return (NULL);
	return (ft_strcpy(ft_strcpy(join, s1) + len_s1, s2));
}
