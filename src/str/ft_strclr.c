/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:23:13 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 20:52:50 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	uint64_t	*wptr;

	while (!ft_isaligned((const void *)s, sizeof(wptr)))
	{
		if (*s == '\0')
			return ;
		*s++ = 0;
	}
	wptr = (uint64_t *)s;
	while (!ft_detect_null(*wptr))
		*wptr++ = (uint64_t)0;
	s = (char *)wptr;
	while (*s != '\0')
		*s++ = 0;
}
