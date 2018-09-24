/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:43:30 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 21:06:03 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;

	if ((s2 = (char *)malloc(ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	return (ft_strcpy(s2, s1));
}
