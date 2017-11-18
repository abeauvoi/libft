/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 21:10:20 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/11/18 17:31:16 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H
# include <limits.h>
# include <stdint.h>
# include <string.h>

# define MASK01 0x0101010101010101UL
# define MASK80 0x8080808080808080UL

# define LONGPTR_MASK (sizeof(long) - 1)

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

#endif
