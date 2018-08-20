/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:39:27 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 08:58:33 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	access_branch_table(t_ftpf_info *info)
{
	static int	(*const branch_tbl[sizeof(CONVERSION_SPECS) - 1])(t_ftpf_info *)
		= {
			handle_bin_int,
			handle_char,
			handle_wchar,
			handle_dec_int,
			handle_dec_int,
			handle_dec_int,
			handle_oct_int,
			handle_hex_int,
			handle_hex_str,
			handle_str,
			handle_wstr,
			handle_dec_uint,
			handle_dec_uint,
			handle_hex_int,
			handle_hex_int
		};
	char		*addr_spec;

	if ((addr_spec = ft_strchr(CONVERSION_SPECS, info->dup_fmt[-1])) != NULL)
		branch_tbl[(ptrdiff_t)(addr_spec - CONVERSION_SPECS)](info);
}
