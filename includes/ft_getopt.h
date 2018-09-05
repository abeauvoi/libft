/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:58:50 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/13 05:03:24 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

typedef struct 	s_getopt
{
	char 	*optarg;
	int 	opterr;
	int 	optopt;
	int 	optind;
	int 	optreset;
}				t_getopt;

# define OPTARG 	(g_getopt.optarg)
# define OPTERR 	(g_getopt.opterr)
# define OPTOPT 	(g_getopt.optopt)
# define OPTIND 	(g_getopt.optind)
# define OPTRESET	(g_getopt.optreset)

static t_getopt 	g_getopt;

struct 			s_getopt_internal
{
	int 				argc;
	char		 		**argv;
	const char 			*optstring;
	char 				*nextchar;
	bool				initialized;
	bool 				print_errors;
	int 				(*cmpf)(const char *, const char *, size_t);
	int 				flags;
	int 				first_nonopt;
	int 				last_nonopt;
};

bool 					is_option(const char *arg);
bool 					is_double_dash(const char *arg);
void 					swap_args_with_options(char **argv,
		struct s_getopt_internal *d);
int 					ft_getopt(int argc, char *const argv[],
		const char *optstring);
void 					case_optional_argument(struct s_getopt_internal *d);

#endif
