/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 04:53:24 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 00:49:05 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_bin_int(t_ftpf_info *info)
{
	t_u8	len;

	if (info->arg.i)
	{
		info->prefix += 9;
		info->prefix_len = 2;
	}
	if ((len = ft_u64toa_b2(((t_u64)info->arg, NULL)) < info->prec)
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg && !info->prec)
		info->workptr = info->endptr;
	else
		info->prec = MAX(info->prec, len + (info->arg == 0));
	return (NEED_PADDING);
}
