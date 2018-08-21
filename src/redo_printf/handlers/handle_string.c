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

#include "ft_printf.h"

FORCE_INLINE int	handle_str(t_ftpf_info *info)
{
	info->workptr = (info->arg.p ? info->arg.p : "(null)");
	info->endptr = ft_memchr(info->workptr, '\0', info->prec);
	if (info->endptr == NULL)
		info->endptr = info->workptr + info->prec;
	else
		info->prec = info->endptr - info->workptr;
	info->flags &= ~ZERO_PAD;
	return (NEED_PADDING);
}

FORCE_INLINE int	handle_wstr(t_ftpf_info *info)
{
	wchar_t		*ws;
	int			mblen;
	int			i;
	char		mbs[5];

	ws = info->arg.p;
	i = 0;
	while (i < 0U + info->prec && *ws
			&& (mblen = ft_wchar_to_utf8(mbs, *ws++)) != -1
			&& mblen <= 0U + info->prec - i)
		i += mblen;
	if (mblen == -1)
		return (-1);
	info->prec = i;
	pad_buffer(info->width, info->prec, info->flags, info);
	ws = info->arg.p;
	i = 0;
	while (i < 0U + info->prec && *ws
			&& i + (mblen = ft_wchar_to_utf8(mbs, *ws++)) <= info->prec)
	{
		mbs[mblen] = '\0';
		str_to_internal_buf(mbs, info);
		i += mblen;
	}
	pad_buffer(info->width, info->prec, info->flags ^ LEFT_ADJ, info);
	info->len = (info->width > info->prec ? info->width : info->prec);
	return (1);
}