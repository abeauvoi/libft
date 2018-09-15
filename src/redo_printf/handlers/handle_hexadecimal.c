/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:49:16 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/15 19:55:42 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					handle_hex_int(t_ftpf *info)
{
	if (info->dup_fmt[-1] == 'p')
	{
		info->prec = MAX(info->prec, 2 * sizeof(void *));
		info->flags |= ALT;
	}
	info->len = ft_u64toa_b16(info->arg, info->convbuf,
			info->dup_fmt[-1] & 0x20);
	if ((t_u64)info->arg != 0 && (info->flags & ALT) != 0)
	{
		info->prefix_len = 2;
		info->prefix += (info->dup_fmt[-1] >> 4);
	}
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if ((t_u64)info->arg == 0 && info->prec == 0)
		info->len = 0;
	else
		info->prec = MAX(info->prec, info->len);
	return (handle_padding(info));
}

static int			ft_hexstrlen(const char *s, int prec)
{
	int 			len;

	len = 0;
	while (*s && len <= prec) 
	{
		if (ft_isprint(*s))
			++len;
		else
			len += 4;
		++s;
	}
	return (len);
}

static void			ft_hexstrcpy(char *wp, char *ep, t_u8 locase, t_ftpf *info)
{
	char	esc_seq[5];

	esc_seq[0] = '\\';
	esc_seq[1] = 'X' | locase;
	esc_seq[4] = '\0';
	while (wp != ep)
	{
		if (!ft_isprint(*wp))
		{
			esc_seq[2] = XDIGITS_UPCASE[((*wp >> 4) & 0xf)] | locase;
			esc_seq[3] = XDIGITS_UPCASE[(*wp & 0xf)] | locase;
			str_to_internal_buf(esc_seq, info);
		}
		else
			char_to_internal_buf(*wp, info);
		++wp;
	}
}

int					handle_hex_str(t_ftpf *info)
{
	char 	*wp;
	char 	*ep;
	t_u8 	locase;

	locase = (info->dup_fmt[-1] & 0x20);
	wp = (info->arg != NULL ? (char *)info->arg : "(null)");
	ep = ft_memchr(wp, '\0', info->prec);
	if (ep == NULL)
		ep = wp + info->prec;
	else
		info->prec = ep - wp;
	info->flags &= ~ZERO_PAD;
	info->prec = ft_hexstrlen(wp, info->prec);
	pad_internal_buf(info->width, info->prec, info->flags, info);
	ft_hexstrcpy(wp, ep, locase, info);
	pad_internal_buf(info->width, info->prec, info->flags ^ LEFT_ADJ, info);
	return (MAX(info->width, info->prec));
}
