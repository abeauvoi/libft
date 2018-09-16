/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:34:15 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 03:36:46 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			char_to_internal_buf(char c, t_ftpf *info)
{
	if (info->bufpos == FT_PRINTF_BUFSZ)
	{
		if (info->outf(info->redir, info->buf, info->bufpos) == -1)
			return (-1);
		else
			info->bufpos = 0;
	}
	info->buf[info->bufpos++] = c;
	return (1);
}

int			flush_internal_buf(t_ftpf *info)
{
	int		flushed_len;

	flushed_len = (int)MIN(info->bufpos, info->max_length - info->done);
	if (flushed_len < 0)
		flushed_len = 0;
	if (info->outf(info->redir, info->buf, flushed_len) == -1)
		return (-1);
	info->bufpos = 0;
	return (1);
}

int			str_to_internal_buf(const char *str, int len, t_ftpf *info)
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

int			pad_internal_buf(t_u32 flags, char c, t_ftpf *info,
		struct s_ftpf_pad pad_info)
{
	char				*p;
	int					len;
	static const char	blanks[PRINTF_PADSIZE] =
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	static const char	zeroes[PRINTF_PADSIZE] =
	{'0', '0', '0', '0', '0', '0', '0', '0',
		'0', '0', '0', '0', '0', '0', '0', '0'};

	if ((flags & (LEFT_ADJ | ZERO_PAD)) || pad_info.len >= pad_info.width)
		return (0);
	p = (c == ' ' ? blanks : zeroes);
	len = pad_info.width - pad_info.len;
	while (len >= PRINTF_PADSIZE)
	{
		if (str_to_internal_buf(p, PRINTF_PADSIZE, info) == -1)
			return (-1);
		len -= PRINTF_PADSIZE;
	}
	return (str_to_internal_buf(p, len, info));
}
