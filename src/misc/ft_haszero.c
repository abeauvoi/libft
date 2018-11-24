/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:12:06 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/22 18:31:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LOMAGIC 0x0101010101010101ull
#define HIMAGIC 0x8080808080808080ull

inline uint64_t		ft_haszero(uint64_t word)
{
	return ((word - LOMAGIC) & ~(word) & HIMAGIC);
}
