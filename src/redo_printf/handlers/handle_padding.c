/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:39:55 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 03:34:55 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_padding(int len, t_ftpf *info)
{
	t_u32				min_len;
	struct s_ftpf_pad	pad_info;
	t_u32				f;

	if (info->prec < len)
		info->prec = len;
	min_len = info->prefix_len + info->prec;
	if (info->width < min_len)
		info->width = min_len;
	f = info->flags;
	pad_info = (struct s_ftpf_pad){.width = info->width, .len = min_len};
	if (pad_internal_buf(f, ' ', info, pad_info) == -1
			|| str_to_internal_buf(info->prefix, info->prefix_len, info) == -1
			|| pad_internal_buf(f ^ ZERO_PAD, '0', info, pad_info) == -1
			|| pad_internal_buf(0, '0', info,
				(struct s_ftpf_pad){.width = info->prec, .len = len}) == -1
			|| str_to_internal_buf(info->workptr, len, info) == -1
			|| pad_internal_buf(f ^ LEFT_ADJ, ' ', info, pad_info) == -1)
		return (-1);
	return (info->width);
}
