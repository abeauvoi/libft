/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 21:10:20 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 01:17:02 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_str
{
	char	*s;
	size_t	l;
}					t_str;

/*
** Shortened types
*/

typedef unsigned char	t_u8;
typedef unsigned short	t_u16;
typedef unsigned int	t_u32;
typedef unsigned long	t_u64;
typedef short int 		t_s16;
typedef long int 		t_s64;

/*
** ft_getopt
*/

typedef struct		s_ft_getopt
{
	char	**argv;
	int		permute;
	int		optind;
	int		optopt;
	char	*optarg;
	char	errbuf[64];
	int		subopt;
}					t_getopt;

typedef enum		e_ft_getopt_argtype
{
	FT_GETOPT_NONE,
	FT_GETOPT_REQUIRED,
	FT_GETOPT_OPTIONAL
}					t_getopt_argtype;

struct				s_ft_getopt_long
{
	const char			*longname;
	int					shortname;
	t_getopt_argtype	argtype;
};

#endif
