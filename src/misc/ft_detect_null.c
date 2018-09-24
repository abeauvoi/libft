/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:12:06 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/20 18:39:47 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LOMAGIC 0x0101010101010101ull
#define HIMAGIC 0x8080808080808080ull

inline bool		ft_detect_null(uint64_t word)
{
	return ((bool)((word - LOMAGIC) & ~word & HIMAGIC));
}
