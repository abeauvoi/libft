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

static inline void 		_increment_byte_count(t_ftpf_info *info) \
				__attribute__ ((always_inline))
{
	if (info->tot_len >= 0)
	{
		if (info->len > INT_MAX - info->tot_len)
			info->tot_len = -1;
		else
			info->tot_len += info->len;
	}
}

static inline size_t 	_skip_literal_text(t_ftpf_info *info) \
				__attribute__ ((always_inline))
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
	info->a = a;
	info->z = z;
	info->dup_fmt = s;
	return (z - a);
}

static inline void 		_init(t_ftpf_info *info) __attribute__ ((always_inline))
{
	info->z = buf + sizeof(buf) - 1;
	if (info->previous_state
			&& (info->dup_fmt[-1] == 'c'
				|| info->dup_fmt[-1] == 's'))
		info->dup_fmt[-1] &= ~32;
	if (info->flags & LEFT_ADJ)
		info->flags &= ~ZERO_PAD;
}

int 					ft_printf_core(t_ftpf_info *info)
{
	while (true)
	{
		_increment_byte_count(info);
		if (info->dup_fmt[0] == '\0')
			break ;
		info->len = _skip_literal_text(info);
		if (!info->silent)
			//copy from info->a over len char;
		if (info->len)
			continue ;
		parse_flags(info);
		if ((info->width = parse_field_width(info, &info->ap)) < 0)
			return (-1);
		info->precision = parse_precision(info, &info->ap);
		if (parse_size_modifiers(info) == -1)
			return (-1);
		if (info->silent)
			continue ;
		_init(info);
	}
	return (info->tot_len);
}
