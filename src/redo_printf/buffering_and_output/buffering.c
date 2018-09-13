/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:34:15 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 04:49:51 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			char_to_internal_buf(char c, t_ftpf *info)
{
	if (info->max_length > 0)
	{
		if (info->bufpos == FT_PRINTF_BUFSZ)
		{
			if (info->outf(info->redir, info->buf, info->bufpos) == -1)
				return (-1);
			else
				info->bufpos = 0;
		}
		info->buf[info->bufpos++] = c;
		--info->max_length;
	}
	return (1);
}

int 		flush_internal_buf(t_ftpf *info)
{
	int		flushed_len;

	flushed_len = MIN(info->bufpos, info->max_length);
	if (info->outf(info->redir, info->buf, flushed_len) == -1)
		return (-1);
	info->max_length -= flushed_len;
	info->bufpos = 0;
	return (1);
}

int 		str_to_internal_buf(char *str, int len, t_ftpf *info)
{
	while (len > FT_PRINTF_BUFSZ)
	{
		if (info->bufpos != 0 && flush_internal_buf(info) == -1)
			return (-1);
		ft_strncpy(info->buf, str, FT_PRINTF_BUFSZ);
		info->bufpos = FT_PRINTF_BUFSZ;
		len -= FT_PRINTF_BUFSZ;
	}
	if (info->bufpos + len >= FT_PRINTF_BUFSZ
		&& flush_internal_buf(info) == -1)
		return (-1);
	ft_strcpy(info->buf, str);
	info->bufpos = len;
	return (1);
}
