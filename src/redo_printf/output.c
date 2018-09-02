/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:28:21 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 00:26:50 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		out_fd(union u_redir redir, const char *src, size_t len)
{
	if (write(redir.fd, src, len) == -1)
	{
		ft_putstr_fd("In function: "__FUNCTION__": syscall write failed\n", 2);
		return (-1);
	}
	return (1);
}

inline int		out_str(union u_redir redir, const char *src, size_t len)
{
	ft_strncpy(redir.buf, src, len);
	return (1);
}

int 			str_to_internal_buf(char *str, size_t len, t_ftpf *info)
{
	char	last_char;

	last_char = str[len];
	str[len] = '\0';
	if (info->done + len < info->redir_bufsiz
			&& info->bufpos + len > FT_PRINTF_BUFSZ
			&& info->outf(info->redir, info->buf, info->bufpos) == -1)
			return (-1);
	ft_strcpy(info->buf, str);
	str[len] = last_char;
	info->bufpos = len;
	return (1);
}
