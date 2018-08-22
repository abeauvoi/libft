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

inline int	out_null(t_ftpf_info *info)
{
	(void)info;
	return (1);
}

inline int	out_fd(t_ftpf_info *info)
{
	info->workptr = '\0';
	if (write(info->redir.fd, info->buf, info->workptr - info->buf) == -1)
		return (-1);
	info->workptr = info->buf;
	return (1);
}

inline int	out_str(t_ftpf_info *info)
{
	info->workptr = '\0';
	ft_strncpy(info->redir.buf, info->buf,
		MIN(info->redir_bufsz - info->done, info->workptr - info->buf));
	info->workptr = info->buf;
	return (1);
}

inline void	str_to_internal_buf(size_t len, char *dest, t_ftpf_info *info)
{
	if (info->endptr - info->workptr < len)
	{
		;	
	}
}