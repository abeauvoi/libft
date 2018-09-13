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

static t_u8	loop(t_u8 pos, const char *tags, char esc_seq[12], t_ftpf *info)
{
	char 		*wp;
	char		*ep;
	char 		*lookup;
	t_u8 		len;

	while ((ep = ft_strchrset(wp, ";}")) != NULL)
	{
		len = ep - wp;
		if ((lookup = ft_strnstr(tags, wp, len)) == NULL)
			break ;
		if (IS_DIGIT(lookup[len + 1]))
		{
			*((t_s16 *)(esc_seq + pos)) = *((t_s16 *)(lookup + len));
			pos += 2;
		}
		else
			esc_seq[pos++] = lookup[len];
		wp = ep + 1;
		if (ep[0] == ';')
			esc_seq[pos++] = ';';
		else
			break ;
	}
	info->dup_fmt = wp;
	return (pos);
}

/*
** Converts an ft_printf color sequence ("{RED;BGREEN;ULINE}")
** into its ansi equivalent : "^[[31;42;4m"
** @return: length of sequence 
*/

t_u8 		parse_color_tag(t_ftpf *info)
{
	const char 	*const tags = COLOR_TABLE;
	t_u8 		pos;
	char 		esc_seq[12];

	esc_seq[0] = '\e';
	esc_seq[1] = '[';
	info->workptr = info->dup_fmt + 1;
	pos = loop(2, tags, esc_seq, info); 
	esc_seq[pos++] = 'm';
	esc_seq[pos] = '\0';
	if (pos >= 4 && str_to_internal_buf(esc_seq, pos, info) == -1)
		return (-1);
	return (pos >= 4 ? pos : 0);
}