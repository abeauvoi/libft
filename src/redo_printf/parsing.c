/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:37:59 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/04 21:42:31 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Size-modifiers state machine {{{
*/ 

static const t_u8	 	g_states[STOP]['z' - 'A' + 1] = 
{
	{
		S('d') = INT, S('i') = INT, S('o') = UINT, S('u') = UINT, S('x') = UINT,
		S('X') = UINT, S('c') = CHAR, S('C') = INT, S('s') = PTR, S('S') = PTR,
		S('p') = UIPTR, S('l') = LPRE, S('h') = HPRE, S('z') = ZTPRE,
		S('j') = JPRE, S('t') = ZTPRE,
	},
	{
		S('d') = LONG, S('i') = LONG, S('o') = ULONG, S('u') = ULONG,
		S('x') = ULONG, S('X') = ULONG, S('c') = INT, S('s') = PTR,
		S('l') = LLPRE,
	},
	{
		S('d') = LLONG, S('i') = LLONG, S('o') = ULLONG, S('u') = ULLONG,
		S('x') = ULLONG, S('X') = ULLONG, 
	},
	{
		S('d') = SHORT, S('i') = SHORT, S('o') = USHORT, S('u') = USHORT,
		S('x') = USHORT, S('X') = USHORT, S('h') = HHPRE,
	},
	{
		S('d') = CHAR, S('i') = CHAR, S('o') = UCHAR, S('u') = UCHAR,
		S('x') = UCHAR, S('X') = UCHAR, 
	},
	{
		S('d') = PDIFF, S('i') = PDIFF, S('o') = SIZET, S('u') = SIZET,
		S('x') = SIZET, S('X') = SIZET, 
	},
	{
		S('d') = IMAX, S('i') = IMAX, S('o') = UMAX, S('u') = UMAX,
		S('x') = UMAX, S('X') = UMAX, 
	}
};

/*
**}}}
*/

/*
** Returns the logical OR of every valid option flag encountered in this
** conversion specification
*/

uint32_t				parse_flags(t_ftpf *info)
{
	char 	*s;
	t_u32	flags;
	t_u32 	option;

	flags = 0;
	s = info->dup_fmt;
	while (*s - ' ' < ' ' && (FLAGMASK & (option = (1U << (*s - ' ')))))
	{
		flags |= option;
		++s;
	}
	info->dup_fmt = s;
	return (flags);
}

/*
** Retrieves the width of the resulting conversion
*/

uint32_t				parse_field_width(t_ftpf *info, va_list ap)
{
	int 	width;
	char 	*s;

	s = info->dup_fmt;
	if (IS_DIGIT(*s))
		width = ft_atoi_skip(&s);
	else if (*s == '*')
	{
		width = va_arg(ap, int);
		++s;
		if (width < 0)
		{
			info->flags |= LEFT_ADJ;
			width = -width;
		}
	}
	info->dup_fmt = s;
	return (width);
}

/*
** Retrieves the precision of the resulting conversion
*/

int						parse_precision(t_ftpf *info, va_list ap)
{
	int 	precision;
	char 	*s;

	s = info->dup_fmt;
	if (*s == ".")
		precision = ft_atoi_skip(&s[1]);
	else if (s[0] == '.' && s[1] == '*')
	{
		precision = va_arg(ap, int);
		s += 2;
	}
	else
		precision = -1;
	info->dup_fmt = s;
	return (precision);
}	

/*
** Processes every size modifier character, updating a state that will be used
** to cast the return value of va_arg()
*/

void					parse_size_modifiers(t_ftpf *info, va_list ap)
{
	t_u32	state;
	t_u32 	previous_state;
	char 	*s;

	state = 0;
	s = info->dup_fmt;
	while (state < STOP)
	{
		if ((t_u8)(*s - 'A') > 'z' - 'A')
			break ;
		previous_state = state;
		state = g_states[state]S(*s++);
	}
	if ((previous_state & (LPRE | LLPRE)) != 0
			&& (s[-1] == 'c' || s[-1] == 's'))
		s[-1] &= ~32;
	info->arg = call_va_arg(state, ap);
	info->dup_fmt = s;
}

void 		parse_color_tag(t_ftpf *info)
{
	const char 	*tags = COLOR_TABLE;
	char 		*lookup;
	t_u8 		pos;
	t_u8 		len;
	char 		esc_seq[12];

	esc_seq[0] = '\e';
	esc_seq[1] = '[';
	info->workptr = info->dup_fmt + 1;	
	pos = 2;
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
	esc_seq[pos++] = 'm';
	esc_seq[pos] = '\0';
	if (pos != 2)
		str_to_internal_buf(esc_seq, pos, info);
	info->dup_fmt = info->workptr;
}