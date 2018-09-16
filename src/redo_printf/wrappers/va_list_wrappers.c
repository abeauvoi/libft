/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list_wrappers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:14:50 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 01:24:16 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_ftpf		info;

	ft_memset(&info, 0, sizeof(info));
	info.max_length = -1U;
	info.outf = out_fd;
	info.redir.fd = fd;
	info.dup_fmt = (char *)fmt;
	info.prefix = PREFIXES;
	return (ft_printf_core(&info, ap));
}

int			ft_vprintf(const char *fmt, va_list ap)
{
	t_ftpf		info;

	ft_memset(&info, 0, sizeof(info));
	info.max_length = -1U;
	info.dup_fmt = (char *)fmt;
	info.prefix = PREFIXES;
	info.outf = out_fd;
	info.redir.fd = 1;
	return (ft_printf_core(&info, ap));
}

int			ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	t_ftpf		info;
	int			done;

	ft_memset(&info, 0, sizeof(info));
	info.dup_fmt = (char *)fmt;
	info.prefix = PREFIXES;
	info.max_length = -1U;
	info.outf = out_null;
	done = ft_printf_core(&info, ap);
	if (done == -1 || (*ret = (char *)malloc(done + 1)) == NULL)
		return (-1);
	info.max_length = done;
	info.dup_fmt = (char *)fmt;
	info.prefix = PREFIXES;
	info.redir.buf = *ret;
	info.outf = out_str;
	return (ft_printf_core(&info, ap));
}

int			ft_vsprintf(char *str, const char *fmt, va_list ap)
{
	t_ftpf		info;

	ft_memset(&info, 0, sizeof(info));
	info.max_length = -1U;
	info.dup_fmt = (char *)fmt;
	info.prefix = PREFIXES;
	info.redir.buf = str;
	info.outf = out_str;
	return (ft_printf_core(&info, ap));
}

int			ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
	t_ftpf		info;

	ft_memset(&info, 0, sizeof(info));
	info.max_length = size;
	info.dup_fmt = (char *)fmt;
	info.prefix = PREFIXES;
	info.redir.buf = str;
	info.outf = out_str;
	info.max_length = size;
	return (ft_printf_core(&info, ap));
}
