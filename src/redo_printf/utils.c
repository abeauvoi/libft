/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 05:11:05 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 07:06:27 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_skip(const char **str)
{
	int 	acc;
	int 	digit;

	acc = 0;
	while ((digit = TO_DIGIT(*((*str)++))) < 10)
		acc = acc * 10 + digit;
	return (acc);
}

void			pad_buffer(t_ftpf_info *d)
{
	char 	buf[256];
	int 	len;

	if ((d->flags & (LEFT_ADJ | ZERO_PAD)) || d->length >= d->width)
		return ;
	len = d->width - d->length;
	ft_memset(buf, d->ch, (len > sizeof(buf) ? sizeof(buf) : len));
	while (len >= sizeof(buf))
	{
		//output buf content w/ len == sizeof(buf);
		len -= sizeof(buf);
	}
	//output buf w/ len == len;
}

/*
** 0xd800 to 0xdffff are reserved for UTF-16 surrogates
*/

FORCE_INLINE int		is_utf8_elligible(unsigned int wc)
{
	return (wc < 0x110000 && (wc < 0xd800 || wc > 0xdfff));
}

FORCE_INLINE static int	4byte_seq(char *s, wchar_t wchar) \
				__attribute__ ((always_inline,pure))
{
	*s++ = 0xf0 | ((wchar & 0x1c0000) >> 18);
	*s++ = 0x80 | ((wchar & 0x3f000) >> 12);
	*s++ = 0x80 | ((wchar & 0xfc0) >> 6);
	*s = 0x80 | (wchar & 0x3f);
	return (4);
}

int						ft_wchar_to_utf8(char *s, wchar_t wchar)
{
	unsigned int	val;

	val = (unsigned int)wchar;
	if (MB_CUR_MAX == 1 || val < 0x80)
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
		return (4byte_seq(s, val));
	return (-1);
}
