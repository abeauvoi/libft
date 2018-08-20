/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 22:49:16 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 09:14:37 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hex_int(t_ftpf_info *info)
{
	if (info->dup_fmt[-1] == 'p')
	{
		info->precision = MAX(info->precision, 2 * sizeof(void *));
		info->flags |= ALT_FORM;
	}
	info->a = num_to_hex(info->arg.i, info->z, info->dup_fmt[-1] & 32);
	if (info->arg.i && (info->flags & ALT_FORM))
	{
		info->prefix_len = 2;
		info->prefix += (info->dup_fmt[-1] >> 4);
	}
	if (info->prec >= 0)
		info->flags &= ~ZERO_PAD;
	if (!info->arg.i && !info->prec)
		info->a = info->z;
	else
		info->prec = MAX(info->prec, info->z - info->a + !info->arg.i);
}

void	handle_hex_str(t_ftpf_info *info)
{
	int		i;
	char	buf[5];

	buf[0] = '\\';
	buf[1] = 'x' | (info->dup_fmt[-1] & 32);
	buf[4] = '\0';
	info->a = (info->arg.p ? info->arg.p : "(null)");
	info->z = ft_memchr(info->a, '\0', info->prec);
	if (info->z == NULL)
		info->z = info->a + info->prec;
	else
		info->prec = info->z - info->a;
	info->flags &= ~ZERO_PAD;
	i = info->prec;
	// this function should count the length of the non_printable string
	while (i > 0)
	{
		if (!ft_isprint(*(info->a)))
		{
			buf[2] = HEX_DIGITS[((*(info->a) >> 4) & 0xf)];
			buf[3] = HEX_DIGITS[(*(info->a) & 0xf)];
			// copy seq to global_buffer
		}
		else
			// copy *info->a to global_buffer
		++info->a;
		--i;
	}
}
