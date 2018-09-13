/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 05:11:05 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 01:54:41 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Include needed for MB_CUR_MAX
*/

#include <stdlib.h>
#include "ft_printf.h"

int					ft_atoi_skip(const char **str)
{
	int		acc;
	int		digit;

	acc = 0;
	while ((digit = TO_DIGIT(*((*str)++))) < 10)
		acc = acc * 10 + digit;
	return (acc);
}

int					pad_internal_buf(t_u32 width, int len, t_u16 flags,
		t_ftpf *info)
{
	char	buf[256];

	if ((flags & (LEFT_ADJ | ZERO_PAD)) || len >= width)
		return ;
	len = width - len;
	ft_memset(buf, info->pad_char,
			(len > sizeof(buf) ? sizeof(buf) : len));
	while (len >= sizeof(buf))
	{
		if (str_to_internal_buf(buf, sizeof(buf), info) == -1)
			return (-1);
		len -= sizeof(buf);
	}
	return (str_to_internal_buf(buf, len, info));
}

/*
** 0xd800 to 0xdffff are reserved for UTF-16 surrogate pairs
*/

inline int			is_utf8(wchar_t wc)
{
	return (wc > 127 && wc < 0x110000 && (wc < 0xd800 || wc > 0xdfff));
}

static INLINED int	four_byte_seq(char *s, wchar_t wchar)
{
	*s++ = 0xf0 | ((wchar & 0x1c0000) >> 18);
	*s++ = 0x80 | ((wchar & 0x3f000) >> 12);
	*s++ = 0x80 | ((wchar & 0xfc0) >> 6);
	*s = 0x80 | (wchar & 0x3f);
	return (4);
}

int					ft_wchar_to_utf8(char *s, wchar_t wchar)
{
	t_u32	val;

	val = (t_u32)wchar;
	if (val < 0x80 || MB_CUR_MAX == 1)
	{
		*s = (char)val;
		return (1);
	}
	else if (val < 0x800 || MB_CUR_MAX == 2)
	{
		*s++ = 0xc0 | ((val & 0x7c0) >> 6);
		*s = 0x80 | (val & 0x3f);
		return (2);
	}
	else if (val < 0x10000 || MB_CUR_MAX == 3)
	{
		*s++ = 0xe0 | ((val & 0xf000) >> 12);
		*s++ = 0x80 | ((val & 0xfc0) >> 6);
		*s = 0x80 | (val & 0x3f);
		return (3);
	}
	else if (val < 0x110000)
		return (four_byte_seq(s, val));
	return (-1);
}
