/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:06:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 21:07:04 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup2(const char *s1, size_t len_s1)
{
	char	*s2;

	if ((s2 = (char *)malloc(len_s1 + 1)) == NULL)
		return (NULL);
	return (ft_strcpy(s2, s1));
}
