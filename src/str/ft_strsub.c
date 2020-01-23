/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:06:00 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/10/25 16:35:21 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t n)
{
	char	*sub;

	if ((sub = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	ft_strncpy(sub, s + start, n);
	sub[n] = 0;
	return (sub);
}
