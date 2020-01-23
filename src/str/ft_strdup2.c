/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:06:09 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:36:16 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup2(const char *s, size_t n)
{
	char	*dup;

	if ((dup = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	return (ft_strcpy(dup, s));
}
