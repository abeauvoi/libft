/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:37:59 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/19 03:59:17 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Size-modifiers state machine {{{
*/ 

static const t_u8 g_states[STOP]['z' - 'A' + 1] = 
{
	{
		S('d') = INT, S('i') = INT, S('o') = UINT, S('u') = UINT, S('x') = UINT,
		S('X') = UINT, S('c') = CHAR, S('C') = INT, S('s') = PTR, S('S') = PTR,
		S('p') = UIPTR, S('n') = PTR, S('m') = NOARG, S('l') = LPRE, S('h') = HPRE,
		S('z') = ZTPRE, S('j') = JPRE, S('t') = ZTPRE,
	},
	{
		S('d') = LONG, S('i') = LONG, S('o') = ULONG, S('u') = ULONG, S('x') = ULONG,
		S('X') = ULONG, S('c') = INT, S('s') = PTR, S('n') = PTR, S('l') = LLPRE,
	},
	{
		S('d') = LLONG, S('i') = LLONG, S('o') = ULLONG, S('u') = ULLONG,
		S('x') = ULLONG, S('X') = ULLONG, S('n') = PTR,
	},
	{
		S('d') = SHORT, S('i') = SHORT, S('o') = USHORT, S('u') = USHORT,
		S('x') = USHORT, S('X') = USHORT, S('n') = PTR, S('h') = HHPRE,
	},
	{
		S('d') = CHAR, S('i') = CHAR, S('o') = UCHAR, S('u') = UCHAR,
		S('x') = UCHAR, S('X') = UCHAR, S('n') = PTR,
	},
	{
		S('d') = PDIFF, S('i') = PDIFF, S('o') = SIZET, S('u') = SIZET,
		S('x') = SIZET, S('X') = SIZET, S('n') = PTR,
	},
	{
		S('d') = IMAX, S('i') = IMAX, S('o') = UMAX, S('u') = UMAX,
		S('x') = UMAX, S('X') = UMAX, S('n') = PTR,
	}
};

/*
**}}}
*/

void 		parse_flags(t_ftpf_info *info)
{
	char 			*s;
	unsigned int	flags;
	unsigned int 	option;

	flags = 0;
	s = info->dup_fmt;
	while (*s - ' ' < ' ' && (FLAGMASK & (option = (1U << (*s - ' ')))))
	{
		flags |= option;
		++s;
	}
	info->flags = flags;
	info->dup_fmt = s;
}

int 		parse_field_width(t_ftpf_info *info)
{
	int 	width;
	char 	*s;

	s = info->dup_fmt;
	if (IS_DIGIT(*s))
		width = ft_atoi_skip(&s);
	else if (*s == '*')
	{
		width = (!info->silent ? va_arg(*info->ap, int) : 0);
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

int 		parse_precision(t_ftpf_info *info)
{
	int 	precision;
	char 	*s;

	s = info->dup_fmt;
	if (*s == ".")
		precision = ft_atoi_skip(&s[1]);
	else if (s[0] == '.' && s[1] == '*')
	{
		precision = (!info->silent ? va_arg(*info->ap, int) : 0);
		s += 2;
	}
	else
		precision = -1;
	info->dup_fmt = s;
	return (precision);
}	

int 		parse_size_modifiers(t_ftpf_info *info)
{
	int 	state;
	int 	previous_state;
	char 	*s;

	state = 0;
	s = info->dup_fmt;
	while (state < STOP)
	{
		if ((unsigned int)(*s - 'A') > 'z' - 'A')
			return (-1);
		previous_state = state;
		state = g_states[state]S(*s);
	}
	info->state = state;
	info->prev_state = previous_state;
	info->dup_fmt = s;
	return (!state ? -1 : 1);
}