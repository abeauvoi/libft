/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 05:28:53 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:17:02 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_char(t_ftpf *info)
{
	info->prec = 1;
	info->convbuf[0] = (char)info->arg;
	info->convbuf[1] = '\0';
	info->workptr = info->convbuf;
	info->flags &= ~ZERO_PAD;
	return (handle_padding(1, info));
}

int			handle_wchar(t_ftpf *info)
{
	info->wchar[0] = (wchar_t)info->arg;
	info->wchar[1] = 0;
	info->arg = (void *)info->wchar;
	info->prec = -1;
	return (handle_wstr(info));
}
