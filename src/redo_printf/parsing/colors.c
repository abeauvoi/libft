/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:19:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/14 15:32:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*seek_delimiter(char *ptr)
{
	if (ptr[0] == '\0' || ptr[0] == '}')
		return (NULL);
	while (ptr[0] && ptr[0] != ';' && ptr[0] != '}')
		++ptr;
	return (ptr);
}

static uint8_t		copy_value_to_buf(char *lookup, char esc_seq[12],
		uint8_t pos, uint8_t len)
{
	if (ft_isdigit(lookup[len + 1]))
	{
		*((uint16_t *)(esc_seq + pos)) = *((uint16_t *)(lookup + len));
		pos += 2;
	}
	else
		esc_seq[pos++] = lookup[len];
	return (pos);
}

/*
** First, this function locates a delimiter (';' or '}'),
** starting from info->dup_fmt[1] (info->dup_fmt[0] == '{' here).
** The address of the delimiter is stored in head_ptr. By substracting head_ptr
** by tail_ptr, we get the length of a sequence.
**
** Then, it stores the length of the sequence (a sequence being for ex. "RED")
** before saving the address of a potential match in lookup.
** If it fails, the loop is broken.
** If it succeeds, lookup points to the first character of the matched sequence.
** For example, lookup -> R ED31GREEN32...
**
** In order to get the sequence's corresponding ansi value, we check at
** lookup[len + 1] to see if the value is > 9, here with input "RED",
** lookup[len + 1] == '1' (3'1').
** The following value is then copied to &esc_seq[pos];
**
** Finally, the tail_ptr pointer is incremented to point past the previous
** delimiter.
** We also check if head_ptr points to a ';', because we need to copy that ';'
** into esc_seq.
*/

static uint8_t		loop(uint8_t pos, char esc_seq[12], char **dup_fmt)
{
	char		*tail_ptr;
	char		*head_ptr;
	char		*lookup;
	uint8_t		len;

	tail_ptr = (*dup_fmt) + 1;
	lookup = NULL;
	while ((head_ptr = seek_delimiter(tail_ptr)) != NULL)
	{
		len = head_ptr - tail_ptr;
		if (len > 7)
			break ;
		if ((lookup = ft_strnstr_icase(COLOR_TABLE, tail_ptr, len)) == NULL)
			break ;
		pos = copy_value_to_buf(lookup, esc_seq, pos, len);
		tail_ptr = head_ptr + 1;
		if (head_ptr[0] == ';')
			esc_seq[pos++] = ';';
	}
	if (lookup == NULL || len > 7)
		return (2);
	(*dup_fmt) = tail_ptr;
	return (pos);
}

/*
** Converts an ft_printf color sequence ("{RED;BGREEN;ULINE}")
** into its ansi equivalent ("^[[31;42;4m").
** Returns the length of the converted sequence
** See ft_printf.h for the syntax of the COLOR_TABLE string literal
**
** In case we parsed an invalid sequence, we skip the starting '{' to avoid an
** infinite loop.
*/

uint8_t				parse_color_tag(t_ftpf *info)
{
	uint8_t	pos;
	char	esc_seq[12];

	esc_seq[0] = '\e';
	esc_seq[1] = '[';
	pos = loop(2, esc_seq, &(info->dup_fmt));
	if (pos == 2)
	{
		char_to_internal_buf(*info->dup_fmt, info);
		++info->dup_fmt;
		return (1);
	}
	esc_seq[pos++] = 'm';
	esc_seq[pos] = '\0';
	if (str_to_internal_buf(esc_seq, pos, info) == -1)
		return (-1);
	return (pos);
}
