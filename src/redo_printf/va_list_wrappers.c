/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list_wrappers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:14:50 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 01:53:34 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_ftpf_info		info;

	ft_memset(&info, 0, sizeof(info));
	info.outf = out_fd;
	info.redir.fd = fd;
	info.dup_fmt = (char *)fmt;
	info.ap = ap;
	info.prefix = PREFIXES;
	return (ft_printf_core(&info));
}

int			ft_vprintf(const char *fmt, va_list ap)
{
	t_ftpf_info		info;

	ft_memset(&info, 0, sizeof(info));
	info.dup_fmt = (char *)fmt;
	info.ap = ap;
	info.prefix = PREFIXES;
	info.outf = out_fd;
	info.redir.fd = STDOUT_FILENO;
	return (ft_printf_core(&info));
}

int			ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	t_ftpf_info		info;
	int				ret;

	ft_memset(&info, 0, sizeof(info));
	info.dup_fmt = (char*)fmt;
	info.ap = ap;
	info.prefix = PREFIXES;
	info.silent = true;
	total_len = ft_printf_core(&info);
	if (total_len == -1 || (*ret = (char*)malloc(total_len + 1)) == NULL)
		return (-1);
	info.dup_fmt = (char*)fmt;
	info.prefix = PREFIXES;
	info.ap = ap;
	info.silent = false;
	info.redir.outbuf = *ret;
	return (ft_printf_core(&info));
}

int			ft_vsprintf(char *str, const char *fmt, va_list ap)
{
	t_ftpf_info		info;

	ft_memset(&info, 0, sizeof(info));
	info.dup_fmt = (char*)fmt;
	info.ap = ap;
	info.prefix = PREFIXES;
	info.redir.outbuf = str;
	return (ft_printf_core(&info));
}

int			ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
	t_ftpf_info		info;

	ft_memset(&info, 0, sizeof(info));
	info.dup_fmt = (char*)fmt;
	info.ap = ap;
	info.prefix = PREFIXES;
	info.redir.outbuf = str;
	info.outbufsz = size;
	return (ft_printf_core(&info));
}
