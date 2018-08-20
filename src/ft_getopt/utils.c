/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 23:26:40 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/13 05:03:24 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getopt.h"

inline bool 	is_option(const char *arg)
{
	return (arg[0] == '-' && arg[1] != '\0' && arg[1] != '-');
}

inline bool 	is_double_dash(const char *arg)
{
	return (arg[0] == '-' && arg[1] == '-' && arg[2] == '\0');
}

static int 		core(char **argv, int bottom, int start, int len)
{
	int 	i;
	char 	*tmp;

	i = 0;
	while (i < len)
	{
		tmp = argv[bottom + i];
		argv[bottom + i] = argv[start + i];
		argv[start + i] = tmp;
		++i;
	}
	return (len);
}

void 			swap_args_with_options(char **argv, struct s_getopt_internal *d)
{
	int 	top;
	int 	middle;
	int 	bottom;

	top = g_getopt.optind;
	middle = d->last_nonopt;
	bottom = d->first_nonopt;
	while (top > middle && middle > bottom)
	{
		if (top - middle > middle - bottom)
			top -= core(argv, bottom, top - (middle - bottom), middle - bottom);
		else
			bottom += core(argv, bottom, middle, top - middle);
	}
	d->first_nonopt += g_getopt.optind - d->last_nonopt;
	d->last_nonopt = g_getopt.optind;
}
