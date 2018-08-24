/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 06:47:14 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 07:32:37 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void 	_increment_byte_count(t_ftpf_info *info)
{
	if (info->done >= 0)
	{
		if (info->len > INT_MAX - info->done)
			info->done = -1;
		else
			info->done += info->len;
	}
}

static size_t	_skip_literal_text(char *s, t_ftpf_info *info)
{
	char 	*a;
	char 	*z;

	a = s;
	while (*s != '\0' && *s != '%')
		++s;
	z = s;
	while (s[0] == '%' && s[1] == '%')
	{
		++z;
		s += 2;
	}
	info->workptr = a;
	info->endptr = z;
	info->dup_fmt = s;
	return (z - a);
}

/*
** @TODO: finish refactoring, conversion handlers and generic padding
*/

int				ft_printf_core(t_ftpf_info *info, va_list ap)
{
	size_t	len;

	while (1)
	{
		_increment_byte_count(info);
		if (info->dup_fmt[0] == '\0')
			break ;
		len = _skip_literal_text(info->dup_fmt, info);
		if (len)
		{
			str_to_internal_work(info->workptr, len, info);
			continue ;
		}
		info->flags = parse_flags(info);
		if ((info->width = parse_field_width(info, ap)) < 0)
			return (-1);
		info->prec = parse_precision(info, ap);
		if (parse_size_modifiers(info, ap) == -1)
			return (-1);
		access_branch_table(info);
	}
	return (info->done);
}
