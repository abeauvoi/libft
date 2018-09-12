/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 08:16:28 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 01:43:36 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					handle_str(t_ftpf *info)
{
	info->workptr = (info->arg != NULL ? (char *)info->arg : "(null)");
	info->endptr = ft_memchr(info->workptr, '\0', info->prec);
	if (info->endptr == NULL)
		info->endptr = info->workptr + info->prec;
	else
		info->prec = info->endptr - info->workptr;
	info->flags &= ~ZERO_PAD;
	return (NEED_PADDING);
}

static INLINED void	ft_wstrcpy(char mbs[5], t_u8 mblen, wchar_t *ws,
		t_ftpf *info)
{
	int		i;

	i = 0;
	while (i < 0U + info->prec
			&& *ws
			&& i + (mblen = ft_wchar_to_utf8(mbs, *ws++)) <= info->prec)
	{
		mbs[mblen] = '\0';
		str_to_internal_buf(mbs, info);
		i += mblen;
	}
}

int					handle_wstr(t_ftpf *info)
{
	char		mbs[5];
	wchar_t		*ws;
	t_u8		mblen;
	int			i;

	ws = (wchar_t *)info->arg;
	i = 0;
	while (i < 0U + info->prec
			&& *ws
			&& (mblen = ft_wchar_to_utf8(mbs, *ws++)) != -1
			&& mblen <= 0U + info->prec - i)
		i += mblen;
	if (mblen == -1)
		return (-1);
	info->prec = i;
	pad_buffer(info->width, info->prec, info->flags, info);
	ft_wstrcpy(mbs, mblen, (wchar_t *)info->arg, info);
	pad_buffer(info->width, info->prec, info->flags ^ LEFT_ADJ, info);
	info->len = MAX(info->width, info->prec); 
	return (DONE);
}
