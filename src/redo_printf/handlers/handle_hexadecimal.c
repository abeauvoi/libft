/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:49:16 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/03 00:59:53 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_hex_int(t_ftpf_info *info)
{
	size_t	conv_len;

	if (info->dup_fmt[-1] == 'p')
	{
		info->prec = MAX(info->prec, 2 * sizeof(void *));
		info->flags |= ALT;
	}
	conv_len = (int)ft_u64toa_b16(info->arg, info->num_buf
			info->dup_fmt[-1] & 0x20);
	if (info->arg.i && (info->flags & ALT))
	{
		info->prefix_len = 2;
		info->prefix += (info->dup_fmt[-1] >> 4);
	}
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->workptr = info->endptr;
	else
		info->prec = MAX(info->prec, info->len);
	return (1);
}

static int 	ft_hexstrlen(const char *s, int prec)
	__attribute__ ((always_inline))
{
	int 			len;

	len = 0;
	while (*s && len <= prec) 
	{
		len += (ft_isprint(*s) ? 1 : 4);
		++s;
	}
	return (len);
}

int 		handle_hex_str(t_ftpf_info *info)
{
	char	esc_seq[5];
	char 	*wp;
	char 	*ep;
	int 	to_lowercase;

	to_lowercase = (info->dup_fmt[-1] & 0x20);
	esc_seq[0] = '\\';
	esc_seq[1] = 'X' | to_lowercase;
	esc_seq[4] = '\0';
	wp = (info->arg != NULL ? info->arg : "(null)");
	ep = ft_memchr(wp, '\0', info->prec);
	if (ep == NULL)
		ep = wp + info->prec;
	else
		info->prec = ep - wp;
	info->flags &= ~ZERO_PAD;
	info->prec = _ft_hexstrlen(wp, info->prec);
	pad_buffer(info->width, info->prec, info->flags, info);
	while (wp != ep)
	{
		if (!ft_isprint(*wp))
		{
			esc_seq[2] = XDIGITS_U[((*wp >> 4) & 0xf)] | to_lowercase;
			esc_seq[3] = XDIGITS_U[(*wp & 0xf)] | to_lowercase;
			str_to_internal_buf(esc_seq, info);
		}
		else
			char_to_internal_buf(*wp, info);
		++wp;
	}
	pad_buffer(info->width, info->prec, info->flags ^ LEFT_ADJ, info);
	info->len = (info->width > info->prec ? info->width : info->prec);
}
