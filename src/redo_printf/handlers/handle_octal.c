/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:03:07 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:23:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_oct_int(t_ftpf *info)
{
	uint64_t	nb;

	nb = (uint64_t)info->arg;
	if (nb != 0 && (info->flags & ALT) != 0)
	{
		info->prefix_len = 1;
		info->prefix += 5;
	}
	info->workptr = info->convbuf;
	return (handle_padding(ft_u64toa_b8(nb, info->convbuf), info));
}
