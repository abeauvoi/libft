/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:49:16 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 04:28:24 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int								handle_hex_int(t_ftpf *info)
{
	unsigned long int	nb;
	int					len;
	unsigned short int	to_lower;	

	to_lower = (info->dup_fmt[-1] & 0x20);
	to_lower |= (to_lower << 8);
	nb = (unsigned long int)info->arg;
	if (info->dup_fmt[-1] == 'p')
	{
		info->prec = MAX(info->prec, 2 * sizeof(void *));
		info->flags |= ALT;
	}
	len = ft_u64toa_b16(nb, info->convbuf, to_lower);
	if (nb != 0 && (info->flags & ALT) != 0)
	{
		info->prefix_len = 2;
		info->prefix += ((unsigned char)info->dup_fmt[-1] / 16);
	}
	if (info->prec != -1)
		info->flags &= ~ZERO_PAD;
	if (nb == 0 && info->prec == 0)
		len = 0;
	info->workptr = info->convbuf;
	return (handle_padding(len, info));
}

static int						ft_hexstrlen(const char *s, int prec)
{
	int		len;
	char	*t;	

	len = 0;
	t = s;
	while (*s)
	{
		if (ft_isprint(*s))
			++len;
	}
	return (len);
}

/*
** Binary lookup table of every hexadecimal digit pair of
** the ascii control characters (from 0 to 31).
** Every pair is inverted because of the machine's endianness.
** The goal here is to write the 2 characters representing the hexadecimal
** value of the control character at once in the esc_seq buffer.
*/

static const unsigned short int	g_digits31[31] = {
	0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3830,
	0x3930, 0x4130, 0x4230, 0x4330, 0x4430, 0x4530, 0x4630, 0x3031, 0x3131,
	0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731, 0x3831, 0x3931, 0x4131,
	0x4231, 0x4331, 0x4431, 0x4531, 0x4631 };
/*
** See ft_u64toa/ft_u64toa_b16.c for a more detailed explanation of
** this algorithm.
*/

static int						ft_hexstrcpy(char *wp, char *ep,
		unsigned short int to_lower, t_ftpf *info)
{
	static char		esc_seq[5] = {'\\', 'X', '\0', '\0', '\0'};

	esc_seq[1] |= (unsigned char)to_lower;
	while (wp != ep)
	{
		if (!ft_isprint(*wp))
		{
			*((short int *)(esc_seq + 2)) = g_digits31[*wp] | to_lower;
			if (str_to_internal_buf(esc_seq, 4, info) == -1)
				return (-1);
		}
		else if (char_to_internal_buf(*wp, info) == -1)
			return (-1);
		++wp;
	}
	return (1);
}

int								handle_hex_str(t_ftpf *info)
{
	char				*wp;
	char				*ep;
	unsigned short int	to_lower;
	struct s_ftpf_pad	pad_info;
	unsigned int		f;

	to_lower = (info->dup_fmt[-1] & 0x20);
	to_lower |= (to_lower << 8);
	wp = (info->arg != NULL ? (char *)info->arg : "(null)");
	ep = ft_memchr(wp, '\0', info->prec);
	if (ep == NULL)
		ep = wp + info->prec;
	else
		info->prec = ep - wp;
	info->flags &= ~ZERO_PAD;
	f = info->flags;
	pad_info = (struct s_ftpf_pad){ .width = info->width, .len = info->prec };
	if (pad_internal_buf(f, ' ', info, pad_info) == -1
			|| ft_hexstrcpy(wp, ep, to_lower, info) == -1
			|| pad_internal_buf(f ^ LEFT_ADJ, ' ', info, pad_info) == -1)
		return (-1);
	return (ft_max(info->width, info->prec));
}
