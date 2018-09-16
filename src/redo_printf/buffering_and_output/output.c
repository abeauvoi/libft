/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:28:21 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 02:56:18 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** include needed for write
*/

#include <unistd.h>
#include "ft_printf.h"

inline int		out_fd(union u_redir redir, const char *str, size_t len)
{
	if (write(redir.fd, str, len) == -1)
	{
		ft_putstr_fd("write failed in function ft_printf_core\n", 2);
		return (-1);
	}
	return (1);
}

inline int		out_str(union u_redir redir, const char *str, size_t len)
{
	ft_strncpy(redir.buf, str, len);
	return (1);
}

inline int		out_null(union u_redir UNUSED(redir), const char UNUSED(*str),
		size_t UNUSED(len))
{
	return (1);
}

inline int		out_stream(union u_redir redir, const char *str, size_t len)
{
	if (ft_fwrite((void *)str, sizeof(char), len, redir.stream) == -1)
	{
		ft_putstr_fd("ft_fwrite failed in function ft_printf_core\n", 2);
		return (-1);
	}
	return (1);
}
