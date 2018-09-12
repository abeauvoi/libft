/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:03:07 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 01:34:31 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_oct_int(t_ftpf_info *info)
{
	info->len = ft_u64toa_b8((t_u64)info->arg, info->convbuf);
	if ((t_u64)info->arg != 0 && (info->flags & ALT) != 0)
	{
		info->prefix_len = 1;
		info->prefix += 5;
	}
	return (NEED_PADDING);
}
