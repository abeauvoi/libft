/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:19:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/12 03:26:44 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	loop(t_u8 pos, const char *tags, char esc_seq[12], t_ftpf *info)
{
	char 		*lookup;

	while ((info->endptr = ft_strchrset(info->workptr, ";}")) != NULL)
	{
		info->len = info->endptr - info->workptr;
		if ((lookup = ft_strnstr(tags, info->workptr, info->len)) == NULL)
			break ;
		if (IS_DIGIT(lookup[info->len + 1]))
		{
			*((t_s16 *)(esc_seq + pos)) = *((t_s16 *)(lookup + info->len));
			pos += 2;
		}
		else
			esc_seq[pos++] = lookup[info->len];
		info->workptr = info->endptr + 1;
		if (info->endptr[0] == ';')
			esc_seq[pos++] = ';';
		else
			break ;
	}
	return (pos);
}

void 		parse_colors(t_ftpf *info)
{
	const char 	*tags = COLOR_TABLE;
	t_u8 		pos;
	char 		esc_seq[12];

	esc_seq[0] = '\e';
	esc_seq[1] = '[';
	info->workptr = info->dup_fmt + 1;
	pos = loop(2, tags, esc_seq, info); 
	esc_seq[pos++] = 'm';
	esc_seq[pos] = '\0';
	if (pos >= 4)
		str_to_internal_buf(esc_seq, pos, info);
	info->dup_fmt = info->workptr;
}
