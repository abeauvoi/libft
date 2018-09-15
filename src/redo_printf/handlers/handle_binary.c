/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 04:53:24 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/15 17:39:44 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_bin_int(t_ftpf_info *info)
{
	if ((t_u64)info->arg != 0)
	{
		info->prefix += 9;
		info->prefix_len = 2;
	}
	info->len = ft_u64toa_b2((t_u64)info->arg, info->convbuf);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if ((t_u64)info->arg == 0 && info->prec == 0)
		info->len = 0;
	else if (info->prec < info->len)
		info->prec = info->len;
	return (handle_padding(info));
}
