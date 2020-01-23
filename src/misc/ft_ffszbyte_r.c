/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ffszbyte_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:53:17 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/01/23 20:07:10 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LOMAGIC 0x0101010101010101ULL
#define HIMAGIC 0x8080808080808080ULL

uint64_t		ft_ffszbyte_r(uint64_t lword)
{
	return ((lword - LOMAGIC) & ~lword & HIMAGIC);
}
