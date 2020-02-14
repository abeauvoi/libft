/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:37:59 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:42:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Size-modifiers state machine {{{
*/ 


static const uint8_t	g_states[STOP]['z' - 'A' + 1] = {
	{
		['b' - 'C'] = UINT, ['c' - 'A'] = CHAR, ['d' - 'A'] = INT,
		['h' - 'A'] = HPRE, ['i' - 'A'] = INT, ['j' - 'A'] = JPRE,
		['l' - 'A'] = LPRE, ['o' - 'A'] = UINT, ['s' - 'A'] = PTR,
		['u' - 'A'] = UINT, ['x' - 'A'] = UINT, ['X' - 'A'] = UINT,
		['C' - 'A'] = INT, ['S' - 'A'] = PTR, ['p' - 'A'] = UIPTR,
		['z' - 'A'] = ZTPRE, ['t' - 'A'] = ZTPRE
	},
	{
		['d' - 'A'] = LONG, ['i' - 'A'] = LONG, ['o' - 'A'] = ULONG,
		['u' - 'A'] = ULONG, ['x' - 'A'] = ULONG, ['X' - 'A'] = ULONG,
		['c' - 'A'] = INT, ['s' - 'A'] = PTR, ['l' - 'A'] = LLPRE
	},
	{
		['d' - 'A'] = LONG, ['i' - 'A'] = LONG, ['o' - 'A'] = ULONG,
		['u' - 'A'] = ULONG, ['x' - 'A'] = ULONG, ['X' - 'A'] = ULONG
	},
	{
		['d' - 'A'] = SHORT, ['i' - 'A'] = SHORT, ['o' - 'A'] = USHORT,
		['u' - 'A'] = USHORT, ['x' - 'A'] = USHORT, ['X' - 'A'] = USHORT,
		['h' - 'A'] = HHPRE
	},
	{
		['d' - 'A'] = CHAR, ['i' - 'A'] = CHAR, ['o' - 'A'] = UCHAR,
		['u' - 'A'] = UCHAR, ['x' - 'A'] = UCHAR, ['X' - 'A'] = UCHAR 
	},
	{
		['d' - 'A'] = PDIFF, ['i' - 'A'] = PDIFF, ['o' - 'A'] = SIZET,
		['u' - 'A'] = SIZET, ['x' - 'A'] = SIZET, ['X' - 'A'] = SIZET 
	},
	{
		['d' - 'A'] = IMAX, ['i' - 'A'] = IMAX, ['o' - 'A'] = UMAX,
		['u' - 'A'] = UMAX, ['x' - 'A'] = UMAX, ['X' - 'A'] = UMAX 
	}
};

/*
**}}}
*/

/*
** Verifies if the parsed character 'flag' falls into the range of recognized
** printf flags. Flags are organized by ascii order.
*/

uint32_t				parse_flags(t_ftpf *info)
{
	char 		*s;
	uint32_t	flags;
	uint32_t 	flag;

	flags = 0;
	s = info->dup_fmt;
	while (*s - ' ' < ' ' && (FLAGMASK & (flag = (1U << (*s - ' ')))) != 0)
	{
		flags |= flag;
		++s;
	}
	info->dup_fmt = s;
	return (flags);
}

uint32_t				parse_field_width(t_ftpf *info, va_list ap)
{
	int			width;
	const char 	*s;

	width = 0;
	s = info->dup_fmt;
	if (ft_isdigit(*s))
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

int						parse_precision(t_ftpf *info, va_list ap)
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

void					parse_size_modifiers(t_ftpf *info, va_list ap)
{
	uint32_t	state;
	uint32_t 	prev_state;
	char 		*s;

	state = BARE;
	s = info->dup_fmt;
	while (state < STOP)
	{
		if (*s - 'A' > 'z' - 'A')
			break ;
		prev_state = state;
		state = g_states[state][*s++ - 'A'];
	}
	info->dup_fmt = s;
	if (s[-1] == '%')
		return ;
	if ((prev_state & (LPRE | LLPRE)) != 0 && (s[-1] == 'c' || s[-1] == 's'))
		s[-1] &= ~0x20;
	info->arg = call_va_arg(state, ap);
}
