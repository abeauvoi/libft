/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 08:16:28 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 08:47:09 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.f"

int			handle_str(t_ftpf_info *info)
{
	info->a = (info->arg.p ? info.arg.p : "(null)");
	info->z = ft_memchr(info->a, '\0', info->prec);
	if (info->z == NULL)
		info->z = info->a + info->prec;
	else
		info->prec = info->z - info->a;
	info->flags &= ~ZERO_PAD;
	return (NEED_PADDING);
}

int			handle_wstr(t_ftpf_info *info)
{
	wchar_t		*ws;
	int			mblen;
	int			i;
	char		mbs[4];

	ws = info->arg.p;
	i = 0;
	while (i < 0U + info->prec && *ws
			&& (mblen = ft_wchar_to_utf8(mbs, *ws++)) != -1
			&& mblen <= 0U + info->prec - i)
		i += mblen;
	if (mblen == -1)
		return (-1);
	info->prec = i;
	pad_buffer(info, ' ', info->flags);
	ws = info->arg.p;
	i = 0;
	while (i < 0U + info->prec && *ws
			&& i + (mblen = ft_wchar_to_utf8(mbs, *ws++)) <= info->prec)
	{
		// copy to buffer;
		i += mblen;
	}
	pad_buffer(info, ' ', info->flags ^ LEFT_ADJ);
	info->len_conv = (info->width > info->prec ? info->width : info->prec);
	return (1);
}
