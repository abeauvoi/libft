/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 20:42:44 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/13 05:03:24 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getopt.h"

static void ft_getopt_init(int argc, char *const argv[], const char *opstring,
		struct s_getopt_internal *d)
{
	d->argc = argc;
	d->argv = argv;
	d->first_nonopt = OPTIND;
	d->last_nonopt = d->first_nonopt;
	d->print_errors = OPTERR;
	if (optstring[0] == ':')
	{
		++optstring;
		d->print_errors = false;
	}
	d->optstring = optstring;
	OPTERR = 1;
	OPTIND = 1;
	OPTRESET = 0;
	d->initialized = true;
}

static int 	ft_getopt_seek_options(struct s_getopt_internal *d)
{
	if (d->first_nonopt != d->last_nonopt && d->last_nonopt != OPTIND)
		swap_args_with_options((char**)d->argv, d);
	else if (d->last_nonopt != OPTIND)
		d->first_nonopt = OPTIND;
	while (OPTIND < d->argc && !is_option(d->argv[OPTIND]))
		++OPTIND;
	d->last_nonopt = OPTIND;
	if (OPTIND != d->argc && is_double_dash(d->argv[OPTIND]))
	{
		++OPTIND;
		if (d->first_nonopt != d->last_nonopt && d->last_nonopt != OPTIND)
			swap_args_with_options((char**)d->argv, d);
		else if (d->first_nonopt == d->last_nonopt)
			d->first_nonopt = OPTIND;
		d->last_nonopt = d->argc;
		OPTIND = d->argc;
	}
	if (OPTIND == d->argc)
	{
		if (d->first_nonopt != d->last_nonopt)
			d->first_nonopt = OPTIND;
		return (-1);
	}
	if (!is_option(d->argv[OPTIND]))
	{
		OPTARG = d->argv[OPTIND++];
		return (1);
	}
	d->nextchar = d->argv[OPTIND] + 1;
	return (0);
}

static char case_required_argument(struct s_getopt_internal *d, char c)
{
	if (d->nextchar[0] != '\0')
	{
		OPTARG = d->nextchar;
		++OPTIND;
	}
	else if (OPTIND == d->argc)
	{
		if (d->print_errors)
			ft_fprintf(2, "%s: option requires an argument -- %c\n",
					d->argv[0], c);
		OPTOPT = c;
		c = (d->flags & PRINT_ERRORS ? '?' : ':');
	}
	else
		OPTARG = d->argv[OPTIND++];
	d->nextchar = NULL;
	return (c);
}

static int 	ft_getopt_internal(struct s_getopt_internal *d)
{
	char 	c;
	char 	*tmp;

	c = *(d->nextchar++);
	tmp = ft_strchr(d->optstring, c);
	if (d->nextchar[0] == '\0')
		++OPTIND;
	if (tmp == NULL || c == ':')
	{
		if (d->print_errors)
			ft_fprintf(2, "%s: illegal option -- %c\n", d->argv[0], c);
		OPTOPT = c;
		return ('?');
	}
	if (tmp[1] == ':')
	{
		if (tmp[2] == ':')
		{
			if (d->nextchar[0] == '\0')
			{
				OPTARG = nextchar;
				++OPTIND;
			}
			else
				OPTARG = NULL;
			d->nextchar = NULL;
		}
		else
			c = case_required_argument(d, c);
	}
	return (c);
}

/*
** POSIX-compliant implementation, see below for detailed algorithm :
** '+' && '-' in optstring not supported, argv can start by a non-option.
** There is always permutation going on.
** --- https://www.unix.com/man-page/posix/3P/getopt/
*/

int 		ft_getopt(int argc, char *const argv[], const char *optstring)
{
	struct s_getopt_internal 	d;
	int 						status;

	if (OPTIND == 0 || !d.initialized || OPTRESET == 1)
	{
		ft_getopt_init(argc, argv, optstring, &d); 
		d.initialized = true;
	}
	if (d->nextchar == NULL || d->nextchar[0] == '\0'
			&& (status = ft_getopt_seek_options(&d)) != 0)
			return (status);
	return (ft_getopt_internal(d));
}
