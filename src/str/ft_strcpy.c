/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:34:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/01/23 20:19:20 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	char	 		*dst0;
	const uint64_t	*ullsrc;
	uint64_t		*ulldst;

	dst0 = dst;
	if (((uintptr_t)ucsrc & 7) == 0 && ((uintptr_t)ucdst & 7) == 0)
	{
		ullsrc = (const uint64_t *)src;
		ulldst = (uint64_t *)dst;
		while (ft_haszero(*ullsrc) == 0)
			*ulldst++ = *ullsrc++;
		src = (const uint8_t *)ullsrc;
		dst = (uint8_t *)ulldst;
	}
	while ((*dst++ = *src++) != '\0')
		continue ;
	return (dst0);
}
