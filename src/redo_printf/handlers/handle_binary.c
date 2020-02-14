/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 04:53:24 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:12:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_bin_int(t_ftpf *info)
{
	int			len;
	uint64_t	nb;

	nb = (uint64_t)info->arg;
	if (nb != 0)
	{
		info->prefix += 9;
		info->prefix_len = 2;
	}
	len = ft_u64toa_b2(nb, info->convbuf);
	if (info->prec != -1)
		info->flags &= ~ZERO_PAD;
	if (nb == 0 && info->prec == 0)
		len = 0;
	info->workptr = info->convbuf;
	return (handle_padding(len, info));
}
