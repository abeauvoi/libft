/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:39:27 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/15 19:59:41 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Chooses the conversion routine associated with the conversion specifier
** character.
** SPECIFIERS is a string literal containing valid conversion specifiers.
** DO NOT CHANGE THE ORDER OF THE FUNCTION POINTERS initialized in branch_tbl
** The conversion routine for %p is handled as a special case inside
** handle_hexadecimal.
*/

int			access_branch_table(t_ftpf *info)
{
	static int	(*const branch_tbl[sizeof(SPECIFIERS) - 1])(t_ftpf *) =
	{
			handle_percent, handle_bin_int, handle_char, handle_wchar,
			handle_dec_int, handle_dec_int, handle_dec_int,
			handle_oct_int, handle_hex_int, handle_hex_str,
			handle_str, handle_wstr, handle_dec_uint,
			handle_dec_uint, handle_hex_int, handle_hex_int
	};
	char		*addr_spec;

	if (info->flags & LEFT_ADJ)
		info->flags &= ~ZERO_PAD;
	if ((addr_spec = ft_strchr(SPECIFIERS, info->dup_fmt[-1])) != NULL)
		return (branch_tbl[addr_spec - SPECIFIERS](info));
	return (0);
}
