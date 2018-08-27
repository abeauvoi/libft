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

static void 	_increment_done(t_ftpf *info, size_t len)
{
	if (info->done >= 0)
	{
		if (len > INT_MAX - info->done)
			info->done = -1;
		else
			info->done += len;
	}
}

static size_t	_find_conversion_spec(char *s, t_ftpf *info)
{
	char 	*a;
	size_t 	len;

	if (*s == '%' || *s == '{')
		return (0);
	a = ft_strchrset(s, "%{");
	if (a == NULL)
	{
		len = ft_strlen(s);
		info->outf(info->redir, s, len);
	}
	else
		len = a - s;
	info->dup_fmt = s + len;
	return (len);
}

/*
** @TODO: finish refactoring, conversion handlers and generic padding
*/

int				ft_printf_core(t_ftpf *info, va_list ap)
{
	size_t	len;

	while (1)
	{
		_increment_done(info, len);
		if (info->dup_fmt[0] == '\0')
			break ;
		if ((len = _find_conversion_spec(info->dup_fmt, info)) > 0)
			continue ;
		if (info->dup_fmt[0] == '{')
			parse_colors();
		++info->dup_fmt;
		info->flags = parse_flags(info);
		info->width = parse_field_width(info, ap);
		info->prec = parse_precision(info, ap);
		parse_size_modifiers(info, ap);
		access_branch_table(info);
	}
	return (info->done);
}
