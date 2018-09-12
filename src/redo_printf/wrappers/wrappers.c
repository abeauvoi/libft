/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 01:44:19 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 01:49:31 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			done;

	va_start(ap, fmt);
	done = ft_vprintf(fmt, ap);
	va_end(ap);
	return (done);
}

int		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		ap;
	int			done;

	va_start(ap, fmt);
	done = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (done);
}

int		ft_sprintf(char *str, const char *fmt, ...)
{
	va_list		ap;
	int			done;

	va_start(ap, fmt);
	done = ft_vsprintf(str, fmt, ap);
	va_end(ap);
	return (done);
}

int		ft_snprintf(char *str, size_t size, const char *fmt, ...)
{
	va_list		ap;
	int			done;

	va_start(ap, fmt);
	done = ft_vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (done);
}

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list		ap;
	int			done;

	va_start(ap, fmt);
	done = ft_vasprintf(ret, fmt, ap);
	va_end(ap);
	return (done);
}
