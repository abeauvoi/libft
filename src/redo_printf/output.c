/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:28:21 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 01:44:07 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int	out_fd(t_ftpf_info *info)
{
	if (write(info->redir.fd, info->buf, info->workptr - info->buf) == -1)
	{
		ft_putendl_fd("ft_printf_core: write failed for unknown reasons", 2);
		return (-1);
	}
	info->workptr = info->buf;
	return (1);
}

inline int	out_str(t_ftpf_info *info)
{
	ft_strncpy(info->redir.buf, info->buf,
		MIN(info->redir_bufsz - info->done, info->workptr - info->buf));
	info->workptr = info->buf;
	return (1);
}

inline int 	str_to_internal_buf(char *str, size_t len, t_ftpf_info *info)
{
	str[len] = 0;
	if (info->endptr - info->workptr < len)
	{
		if (info->outf(info) == -1)
			return (-1);
	}
	ft_strcpy(info->buf, str);
	return (1);
}