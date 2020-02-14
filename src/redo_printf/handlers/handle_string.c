/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 08:16:28 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:32:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_str(t_ftpf *info)
{
	int		len;

	info->workptr = (info->arg != NULL ? (char *)info->arg : "(null)");
	len = ft_strlen(info->workptr);
	info->flags &= ~ZERO_PAD;
	return (handle_padding(len, info));
}

static int		ft_wstrcpy(char mbs[5], int mblen, wchar_t *ws, t_ftpf *info)
{
	int		i;

	i = 0;
	while (i < info->prec
			&& *ws
			&& i + (mblen = ft_wchar_to_utf8(mbs, *ws++)) <= info->prec)
	{
		mbs[mblen] = '\0';
		if (str_to_internal_buf(mbs, mblen, info) == -1)
			return (-1);
		i += mblen;
	}
	return (1);
}

int				handle_wstr(t_ftpf *info)
{
	char				mbs[5];
	wchar_t				*ws;
	int 				mblen;
	int					i;
	struct s_ftpf_pad	pad_info;

	ws = (wchar_t *)info->arg;
	i = 0;
	while ((unsigned int)i < 0U + info->prec
			&& *ws
			&& (mblen = ft_wchar_to_utf8(mbs, *ws++)) != -1
			&& (unsigned int)mblen <= 0U + info->prec - i)
		i += mblen;
	if (mblen == -1)
		return (-1);
	info->prec = i;
	pad_info = (struct s_ftpf_pad){.width = info->width, .len = info->prec};
	if (pad_internal_buf(info->flags, ' ', info, pad_info) == -1
			|| ft_wstrcpy(mbs, mblen, (wchar_t *)info->arg, info) == -1
			|| pad_internal_buf(info->flags ^ LEFT_ADJ, ' ', info, pad_info)
			== -1)
		return (-1);
	return (ft_max(info->width, info->prec));
}
