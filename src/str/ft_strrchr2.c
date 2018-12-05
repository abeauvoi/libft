/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:20:18 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 22:35:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strrchr2(const char *const str, char c, size_t lenstr)
{
	size_t 	i;

	i = lenstr - 1;
	while (i > 0 && str[i] != c)
		--i;
	return (i);
}
