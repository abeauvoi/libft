/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:28:53 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 01:30:00 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_char(t_ftpf_info *info)
{
	info->prec = 1;
	info->workptr = info->endptr - 1;
	*(info->workptr) = (char)info->arg;
	info->flags &= ~ZERO_PAD;
	return (1);
}

int			handle_wchar(t_ftpf_info *info)
{
	info->wchar[0] = info->arg.i;
	info->wchar[1] = 0;
	info->arg = info->wchar;
	info->prec = -1;
	return (handle_wstr(info));
}
