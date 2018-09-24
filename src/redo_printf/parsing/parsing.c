/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:37:59 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 22:20:19 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Size-modifiers state machine {{{
*/ 


static const t_u8	g_states[STOP]['z' - 'C' + 1] = {
	{
		['b' - 'C'] = UINT, ['c' - 'A'] = CHAR, ['d' - 'A'] = INT,
		['h' - 'A'] = HPRE, ['i' - 'A'] = INT, ['j' - 'A'] = JPRE,
		['l' - 'A'] = LPRE, ['o' - 'A'] = UINT, ['s' - 'A'] = PTR,
		['u' - 'A'] = UINT, ['x' - 'A'] = UINT, ['X' - 'A'] = UINT,
		['C' - 'A'] = INT, ['S' - 'A'] = PTR, ['p' - 'A'] = UIPTR,
		['z' - 'A'] = ZTPRE,
		['t' - 'A'] = ZTPRE
	},
	{
		['d' - 'A'] = LONG, ['i' - 'A'] = LONG, ['o' - 'A'] = ULONG, ['u' - 'A'] = ULONG,
		['x' - 'A'] = ULONG, ['X' - 'A'] = ULONG, ['c' - 'A'] = INT, ['s' - 'A'] = PTR,
		['l' - 'A'] = LLPRE
	},
	{
		['d' - 'A'] = LONG, ['i' - 'A'] = LONG, ['o' - 'A'] = ULONG, ['u' - 'A'] = ULONG,
		['x' - 'A'] = ULONG, ['X' - 'A'] = ULONG
	},
	{
		['d' - 'A'] = SHORT, ['i' - 'A'] = SHORT, ['o' - 'A'] = USHORT, ['u' - 'A'] = USHORT,
		['x' - 'A'] = USHORT, ['X' - 'A'] = USHORT, ['h' - 'A'] = HHPRE
	},
	{
		['d' - 'A'] = CHAR, ['i' - 'A'] = CHAR, ['o' - 'A'] = UCHAR, ['u' - 'A'] = UCHAR,
		['x' - 'A'] = UCHAR, ['X' - 'A'] = UCHAR 
	},
	{
		['d' - 'A'] = PDIFF, ['i' - 'A'] = PDIFF, ['o' - 'A'] = SIZET, ['u' - 'A'] = SIZET,
		['x' - 'A'] = SIZET, ['X' - 'A'] = SIZET 
	},
	{
		['d' - 'A'] = IMAX, ['i' - 'A'] = IMAX, ['o' - 'A'] = UMAX, ['u' - 'A'] = UMAX,
		['x' - 'A'] = UMAX, ['X' - 'A'] = UMAX 
	}
};

/*
**}}}
*/

t_u32				parse_flags(t_ftpf *info)
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

t_u32				parse_field_width(t_ftpf *info, va_list ap)
{
	int			width;
	const char 	*s;

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
	info->dup_fmt = (char *)s;
	return (width);
}

int					parse_precision(t_ftpf *info, va_list ap)
{
	int			precision;
	const char 	*s;

	s = info->dup_fmt;
	if (*s == '.')
	{
		++s;
		precision = ft_atoi_skip(&s);
	}
	else if (s[0] == '.' && s[1] == '*')
	{
		precision = va_arg(ap, int);
		s += 2;
	}
	else
		precision = -1;
	info->dup_fmt = (char *)s;
	return (precision);
}	

void				parse_size_modifiers(t_ftpf *info, va_list ap)
{
	t_u32	state;
	t_u32 	prev_state;
	char 	*s;

	state = BARE;
	s = info->dup_fmt;
	while (state < STOP)
	{
		if (OUT_OF_RANGE(*s))
			break ;
		prev_state = state;
		state = g_states[state][*s++ - 'C'];
	}
	info->dup_fmt = s;
	if (s[-1] == '%')
		return ;
	if ((prev_state & (LPRE | LLPRE)) != 0 && (s[-1] == 'c' || s[-1] == 's'))
		s[-1] &= ~0x20;
	info->arg = call_va_arg(state, ap);
}
