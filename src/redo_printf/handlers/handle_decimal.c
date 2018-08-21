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
	else if (info->flags & PLUS_SIGN)
		++info->prefix;
	else if (info->flags & SPACE)
		info->prefix += 2;
	else
		info->prefix_len = 0;
	info->workptr = num_to_uint(info->arg.i, info->endptr);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->workptr = info->endptr;
	else
		info->prec = MAX(info->prec, info->endptr - info->workptr + !info->arg.i);
}

void	handle_dec_uint(t_ftpf_info *info)
{
	info->workptr = num_to_uint(info->arg.i, info->endptr);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->workptr = info->endptr;
	else
		info->prec = MAX(info->prec, info->endptr - info->workptr + !info->arg.i);
}