/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:49:16 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 03:30:00 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					handle_hex_int(t_ftpf *info)
{
	t_u64	nb;
	int		len;

	nb = (t_u64)info->arg;
	if (info->dup_fmt[-1] == 'p')
	{
		info->prec = MAX(info->prec, 2 * sizeof(void *));
		info->flags |= ALT;
	}
	len = ft_u64toa_b16(nb, info->convbuf, info->dup_fmt[-1] & 0x20);
	if (nb != 0 && (info->flags & ALT) != 0)
	{
		info->prefix_len = 2;
		info->prefix += (info->dup_fmt[-1] >> 4);
	}
	if (info->prec != -1)
		info->flags &= ~ZERO_PAD;
	if (nb == 0 && info->prec == 0)
		len = 0;
	info->workptr = info->convbuf;
	return (handle_padding(len, info));
}

static int			ft_hexstrlen(const char *s, int prec)
{
	int			len;

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

static int			ft_hexstrcpy(char *wp, char *ep, t_u8 locase, t_ftpf *info)
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
			if (str_to_internal_buf(esc_seq, 4, info) == -1)
				return (-1);
		}
		else if (char_to_internal_buf(*wp, info) == -1)
			return (-1);
		++wp;
	}
	return (1);
}

int					handle_hex_str(t_ftpf *info)
{
	char				*wp;
	char				*ep;
	t_u8				locase;
	struct s_ftpf_pad	pad_info;
	t_u32				f;

	locase = (info->dup_fmt[-1] & 0x20);
	wp = (info->arg != NULL ? (char *)info->arg : "(null)");
	ep = ft_memchr(wp, '\0', info->prec);
	if (ep == NULL)
		ep = wp + info->prec;
	else
		info->prec = ep - wp;
	info->flags &= ~ZERO_PAD;
	f = info->flags;
	info->prec = ft_hexstrlen(wp, info->prec);
	pad_info = (struct s_ftpf_pad){ .width = info->width, .len = info->prec};
	if (pad_internal_buf(f, ' ', info, pad_info) == -1
			|| ft_hexstrcpy(wp, ep, locase, info) == -1
			|| pad_internal_buf(f ^ LEFT_ADJ, ' ', info, pad_info) == -1)
		return (-1);
	return (MAX(info->width, info->prec));
}
