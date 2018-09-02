/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:08:54 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 00:54:15 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_dec_int(t_ftpf_info *info)
{
	t_u8	conv_len;
	
	info->prefix_len = 1;
	if ((long int)info->arg < 0)
		info->arg = -(info->arg);
	else if (info->flags & PLUS_SIGN)
		++info->prefix;
	else if (info->flags & SPACE)
		info->prefix += 2;
	else
		info->prefix_len = 0;
	conv_len = ft_u64toa_b10((long int)info->arg, ...);
	info->workptr = num_to_uint(info->arg.i, info->endptr);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->workptr = info->endptr;
	else
		info->prec = MAX(info->prec, conv_len + (info->arg == 0));
}

void	handle_dec_uint(t_ftpf_info *info)
{
	t_u8	conv_len;

	conv_len = ft_u64toa_b10(info->arg, NULL);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->workptr = info->endptr;
	else
		info->prec = MAX(info->prec, conv_len + (info->arg == 0));
}
