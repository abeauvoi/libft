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

int 		str_to_internal_buf(char *str, int len, t_ftpf *info)
{
	size_t	str_pos;

	str_pos = 0;
	while (len > FT_PRINTF_BUFSZ)
	{
		if (info->bufpos)
		{
			if (info->outf(info->redir, info->buf,
						MIN(info->bufpos, info->max_length)) == -1)
				return (-1);
			info->max_length -= info->bufpos;
			info->bufpos = 0;
		}
		ft_strncpy(info->buf, str, FT_PRINTF_BUFSZ);
		info->bufpos = MIN(len
		len -= FT_PRINTF_BUFSZ;
	}
	ft_strcpy(info->buf, str);
	return (1);
}
