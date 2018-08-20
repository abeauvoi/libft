/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 04:53:24 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 08:15:15 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_bin_int(t_ftpf_info *info)
{
	if (info->arg.i)
	{
		info->prefix += 9;
		info->prefix_len = 2;
	}
	info->a = num_to_bin(info->arg.i, info->z);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->a = info->z;
	else
		info->prec = MAX(info->prec, info->z - info->a + !info->arg.i);
}
