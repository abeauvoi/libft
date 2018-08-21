/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 06:47:14 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 01:28:14 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

FORCE_INLINE static void 	_increment_byte_count(t_ftpf_info *info)
{
	if (info->done >= 0)
	{
		if (info->len > INT_MAX - info->done)
			info->done = -1;
		else
			info->done += info->len;
	}
}

FORCE_INLINE static size_t	_skip_literal_text(t_ftpf_info *info)
{
	char 	*s;
	char 	*a;
	char 	*z;

	s = info->dup_fmt;
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

FORCE_INLINE static void	_init(t_ftpf_info *info)
{
	info->pad_char = ' ';
	info->endptr = info->num_buf + sizeof(info->num_buf) - 1;
	if (info->prev_state
			&& (info->dup_fmt[-1] == 'c'
				|| info->dup_fmt[-1] == 's'))
		info->dup_fmt[-1] &= ~32;
	if (info->flags & LEFT_ADJ)
		info->flags &= ~ZERO_PAD;
}

int 						ft_printf_core(t_ftpf_info *info)
{
	while (1)
	{
		_increment_byte_count(info);
		if (info->dup_fmt[0] == '\0')
			break ;
		info->len = _skip_literal_text(info);
		if (!info->silent)
			//copy from info->workptr over len char;
		if (info->len)
			continue ;
		parse_flags(info);
		if ((info->width = parse_field_width(info)) < 0)
			return (-1);
		info->prec = parse_precision(info);
		if (parse_size_modifiers(info) == -1)
			return (-1);
		if (info->silent)
			continue ;
		_init(info);
	}
	return (info->done);
}