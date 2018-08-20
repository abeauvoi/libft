/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:08:54 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 05:27:16 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_dec_int(t_ftpf_info *info)
{
	info->prefix_len = 1;
	if (info->arg.i > INTMAX_MAX)
		info->arg.i = -(info->arg.i);
	else if (info->flags & MARK_POS)
		++info->prefix;
	else if (info->flags & PAD_POS)
		info->prefix += 2;
	else
		info->prefix_len = 0;
	info->a = num_to_uint(info->arg.i, info->z);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->a = info->z;
	else
		info->prec = MAX(info->prec, info->z - info->a + !info->arg.i);
}

void	handle_dec_uint(t_ftpf_info *info)
{
	info->a = num_to_uint(info->arg.i, info->z);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->a = info->z;
	else
		info->prec = MAX(info->prec, info->z - info->a + !info->arg.i);
}
