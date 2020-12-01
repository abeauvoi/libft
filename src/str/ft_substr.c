/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:06:00 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/12/01 20:14:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(const char *s, unsigned int start, size_t n)
{
	char	*sub;

	sub = ft_strnew(n);
	if (sub == NULL)
		return (NULL);
	return (ft_strncpy(sub, s + start, n));
}
