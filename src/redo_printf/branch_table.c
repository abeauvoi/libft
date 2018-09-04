/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:39:27 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/04 21:19:02 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	pad_and_copy_to_internal_buf(t_ftpf *info)
{
	t_u32		min_len;

	if (info->prec < info->len)
		info->prec = info->len;
	min_len = info->prefix_len + info->prec;
	if (info->width < min_len)
		info->width = min_len;
	pad_internal_buf(info->width, min_len, info->flags, info);
	str_to_internal_buf(info->prefix, info->prefix_len, info);
	info->pad_char = '0';
	pad_internal_buf(info->width, min_len, info->flags ^ ZERO_PAD, info);
	pad_internal_buf(info->prec, info->len, 0, info);
	info->pad_char = ' ';
	str_to_internal_buf(info->workptr, info->len, info);
	pad_internal_buf(info->width, min_len, info->flags ^ LEFT_ADJ, info);
	info->len = info->width;
}

void				access_branch_table(t_ftpf *info)
{
	static int	(*const branch_tbl[sizeof(SPECIFIERS) - 1])(t_ftpf *) =
	{
			handle_bin_int, handle_char, handle_wchar,
			handle_dec_int, handle_dec_int, handle_dec_int,
			handle_oct_int, handle_hex_int, handle_hex_str,
			handle_str, handle_wstr, handle_dec_uint,
			handle_dec_uint, handle_hex_int, handle_hex_int
	};
	char		*addr_spec;

	if (info->flags & LEFT_ADJ)
		info->flags &= ~ZERO_PAD;
	info->pad_char = ' ';
	if ((addr_spec = ft_strchr(SPECIFIERS, info->dup_fmt[-1])) != NULL)
		branch_tbl[addr_spec - SPECIFIERS](info);
	pad_and_copy_to_internal_buf(info);
}
