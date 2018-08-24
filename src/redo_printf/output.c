/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:28:21 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 06:51:23 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		out_fd(t_ftpf_info *info)
{
	if (write(info->redir.fd, info->buf, info->bufpos) == -1)
	{
		ft_putstr_fd("ft_printf_core: syscall 'write' failed\n", 2);
		return (-1);
	}
	info->bufptr = info->buf;
	return (1);
}

int		out_str(t_ftpf_info *info)
{
	ft_strncpy(info->redir.buf, info->buf,
		MIN(info->redir_bufsz - info->done, info->bufptr - info->buf));
	info->workptr = info->buf;
	return (1);
}

int 	str_to_internal_buf(char *str, size_t len, t_ftpf_info *info)
{
	char	last_char;

	last_char = str[len];
	str[len] = '\0';
	if (FT_PRINTF_BUFSZ - info->bufpos < len)
	{
		if (info->outf(info) == -1)
			return (-1);
	}
	ft_strcpy(info->buf, str);
	str[len] = last_char;
	info->bufpos = len;
	return (1);
}
