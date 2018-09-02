/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:03:07 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 01:08:37 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_oct_int(t_ftpf_info *info)
{
	t_u8	conv_len;

	conv_len = ft_u64toa_b8((t_u64)info->arg, ...);
	if (info->arg != NULL && (info->flags & ALT))
	{
		info->prefix_len = 1;
		info->prefix += 5;
	}
	return (NEED_PADDING);
}
