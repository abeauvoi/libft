/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:28:21 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 04:32:49 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline int		out_fd(union u_redir redir, const char *src, size_t len)
{
	if (write(redir.fd, src, len) == -1)
	{
		ft_putstr_fd("function " __FUNCTION__ ": syscall write failed\n", 2);
		return (-1);
	}
	return (1);
}

inline int		out_str(union u_redir redir, const char *src, size_t len)
{
	ft_strncpy(redir.buf, src, len);
	return (1);
}

inline int		out_null(union u_redir UNUSED(redir), const char UNUSED(*src),
		size_t UNUSED(len))
{
	return (1);
}

inline int		out_stream(union u_redir redir, const char *src, size_t len)
{
	if (ft_fwrite((void *)str, sizeof(char), len, redir.stream) == -1)
	{
		ft_putstr_fd("function " __FUNCTION__ ": ft_fwrite failed\n", 2);
		return (-1);
	}
	return (1);
}
