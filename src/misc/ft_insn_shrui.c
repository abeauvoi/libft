/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insn_shrui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:49:52 by mac               #+#    #+#             */
/*   Updated: 2018/12/01 14:50:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t 	ft_insn_shrui(uint8_t val[8], uint8_t shift)
{
	return (((uint64_t)(val[0] >> shift) << 0)
			| ((uint64_t)(val[1] >> shift) << 8)
			| ((uint64_t)(val[2] >> shift) << 16)
			| ((uint64_t)(val[3] >> shift) << 24)
			| ((uint64_t)(val[4] >> shift) << 32)
			| ((uint64_t)(val[5] >> shift) << 40)
			| ((uint64_t)(val[6] >> shift) << 48)
			| ((uint64_t)(val[7] >> shift) << 56));
}
