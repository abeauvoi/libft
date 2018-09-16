/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list_wrappers_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:21:27 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 01:43:28 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @TODO: Add stream locking and flushing mechanisms
*/

int			ft_vfprintf(FILE *stream, const char *fmt, va_list ap)
{
	t_ftpf		info;

	ft_memset(&info, 0, sizeof(info));
	info.outf = out_stream;
	info.max_length = -1U;
	info.dup_fmt = (char *)fmt;
	info.prefix = PREFIXES;
	info.redir.stream = stream;
	return (ft_printf_core(&info, ap));
}
