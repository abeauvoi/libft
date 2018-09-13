/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 06:47:14 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 03:27:44 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static INLINED void 	increment_byte_count(t_ftpf *info, int len)
{
	if (info->done >= 0)
	{
		if (len > INT_MAX - info->done)
			info->done = -1;
		else
			info->done += len;
	}
}

static int				find_conversion_spec(char *s, t_ftpf *info)
{
	char 	*a;

	a = s;
	while (*s && *s != '%' && *s != '{')
		++s;
	if (s != a && str_to_internal_buf(a, s - a, info) == -1)
		return (-1);
	return (s - a);
}

int						ft_printf_core(t_ftpf *info, va_list ap)
{
	int		len;

	while (1)
	{
		if (len == -1)
			return (-1);
		increment_byte_count(info, len);
		if (info->dup_fmt[0] == '\0')
			break ;
		if ((len = find_conversion_spec(info->dup_fmt, info)) != 0)
			continue ;
		if (info->dup_fmt[0] == '{')
		{
			len = parse_color_tag(info);
			continue ;
		}
		++info->dup_fmt;
		info->flags = parse_flags(info);
		info->width = parse_field_width(info, ap);
		info->prec = parse_precision(info, ap);
		parse_size_modifiers(info, ap);
		access_branch_table(info);
		len = info->len;
	}
	return (info->done);
}
