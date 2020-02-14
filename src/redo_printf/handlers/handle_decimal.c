/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:08:54 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:14:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_dec_int(t_ftpf *info)
{
	uint64_t	nb;
	int			len;

	nb = (uint64_t)info->arg;
	info->prefix_len = 1;
	if (nb > LONG_MAX)
		nb = -nb;
	else if (info->flags & PLUS_SIGN)
		++info->prefix;
	else if (info->flags & SPACE)
		info->prefix += 2;
	else
		info->prefix_len = 0;
	len = ft_u64toa_b10(nb, info->convbuf);
	if (info->prec != -1)
		info->flags &= ~ZERO_PAD;
	if (nb == 0 && info->prec == 0)
		len = 0;
	info->workptr = info->convbuf;
	return (handle_padding(len, info));
}

int		handle_dec_uint(t_ftpf *info)
{
	uint64_t	nb;
	int			len;

	nb = (uint64_t)info->arg;
	len = ft_u64toa_b10(nb, info->convbuf);
	if (info->prec != -1)
		info->flags &= ~ZERO_PAD;
	if (nb == 0 && info->prec == 0)
		len = 0;
	info->workptr = info->convbuf;
	return (handle_padding(len, info));
}
