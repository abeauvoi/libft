/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:28:53 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 08:48:07 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void		handle_char(t_ftpf_info *info)
{
	info->prec = 1;
	info->workptr = info->endptr - 1;
	*(info->workptr) = (char)info->arg.i;
	info->flags &= ~ZERO_PAD;
}

inline void		handle_wchar(t_ftpf_info *info)
{
	info->wchar[0] = info->arg.i;
	info->wchar[1] = 0;
	info->arg.p = info->wchar;
	info->prec = -1;
	handle_wstr(info);
}