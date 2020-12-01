/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:12:06 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/11/27 17:44:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LOMAGIC 0x0101010101010101ull
#define HIMAGIC 0x8080808080808080ull

uint64_t		ft_detect_null(uint64_t longword)
{
	return ((longword - LOMAGIC) & ~longword & HIMAGIC);
}
