/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:37:59 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 03:50:51 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define S(x) [(x) - 'A']
# define OUT_OF_RANGE(x) (t_u8)((x) - 'A') > (t_u8)('z' - 'A')

/*
** Size-modifiers state machine {{{
*/ 


static const t_u8	g_states[STOP]['z' - 'A' + 1] = 
{
	{
		S('d') = INT, S('i') = INT, S('o') = UINT, S('u') = UINT, S('x') = UINT,
		S('X') = UINT, S('c') = CHAR, S('C') = INT, S('s') = PTR, S('S') = PTR,
		S('p') = UIPTR, S('l') = LPRE, S('h') = HPRE, S('z') = ZTPRE,
		S('j') = JPRE, S('t') = ZTPRE
	},
	{
		S('d') = LONG, S('i') = LONG, S('o') = ULONG, S('u') = ULONG,
		S('x') = ULONG, S('X') = ULONG, S('c') = INT, S('s') = PTR,
		S('l') = LLPRE
	},
	{
		S('d') = LONG, S('i') = LONG, S('o') = ULONG, S('u') = ULONG,
		S('x') = ULONG, S('X') = ULONG
	},
	{
		S('d') = SHORT, S('i') = SHORT, S('o') = USHORT, S('u') = USHORT,
		S('x') = USHORT, S('X') = USHORT, S('h') = HHPRE
	},
	{
		S('d') = CHAR, S('i') = CHAR, S('o') = UCHAR, S('u') = UCHAR,
		S('x') = UCHAR, S('X') = UCHAR 
	},
	{
		S('d') = PDIFF, S('i') = PDIFF, S('o') = SIZET, S('u') = SIZET,
		S('x') = SIZET, S('X') = SIZET 
	},
	{
		S('d') = IMAX, S('i') = IMAX, S('o') = UMAX, S('u') = UMAX,
		S('x') = UMAX, S('X') = UMAX 
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

	state = 0;
	s = info->dup_fmt;
	while (state < STOP)
	{
		if (OUT_OF_RANGE(*s))
# undef OUT_OF_RANGE
			break ;
		prev_state = state;
		state = g_states[state]S(*s++);
# undef S
	}
	info->dup_fmt = s;
	if (s[-1] == '%')
		return ;
	if ((prev_state & (LPRE | LLPRE)) != 0 && (s[-1] == 'c' || s[-1] == 's'))
		s[-1] &= ~0x20;
	info->arg = call_va_arg(state, ap);
}
