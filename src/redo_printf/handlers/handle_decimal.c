/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:08:54 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/15 17:43:47 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_dec_int(t_ftpf_info *info)
{
	t_u64	nb;

	nb = (t_u64)info->arg;
	info->prefix_len = 1;
	if (nb > LONG_MAX)
		nb = -nb;
	else if (info->flags & PLUS_SIGN)
		++info->prefix;
	else if (info->flags & SPACE)
		info->prefix += 2;
	else
		info->prefix_len = 0;
	info->len = ft_u64toa_b10(nb, info->convbuf);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (nb == 0 && info->prec == 0)
		info->len = 0;
	else if (info->prec < conv_len)
		info->prec = info->len;
	return (handle_padding(info));
}

int		handle_dec_uint(t_ftpf_info *info)
{
	info->len = ft_u64toa_b10((t_u64)info->arg, info->convbuf);
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if ((t_u64)info->arg == 0 && info->prec == 0)
		info->len = 0;
	else if (info->prec < info->len)
		info->prec = info->len; 
	return (handle_padding(info));
}
