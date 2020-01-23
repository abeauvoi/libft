/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_haszero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:12:06 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/01/23 20:23:15 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LOMAGIC 0x0101010101010101ull
#define HIMAGIC 0x8080808080808080ull

bool		ft_detect_null(uint64_t longword)
{
	return ((bool)(((longword - LOMAGIC) & ~longword & HIMAGIC) != 0));
}
