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

int		out_null(t_ftpf_info *info)
{
	(void)info;
	return (1);
}

int		out_fd(t_ftpf_info *info)
{
	if (write(info->redir.fd, info->buf, info->workptr - info->buf) == -1)
		return (-1);
	info->workptr = buf;
	return (1);
}

int		out_str(t_ftpf_info *info)
{
	ft_strncpy(info->redir.outbuf, info->buf, MIN(info->outbufsz - info->done,
				info->workptr - info->buf));
	info->work_ptr = buf;
	return (1);
}
