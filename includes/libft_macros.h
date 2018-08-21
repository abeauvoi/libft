/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <abeauvoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 05:06:59 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/20 09:14:32 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H

/*
** Various useful macros {{{
*/
# define XDIGITS_U "0123456789ABCDEF"
# define TO_DIGIT(x) ((unsigned int)(x) - '0')
# define TO_CHAR(x)	((x) + '0')	
# define TO_LOWER(x) ((unsigned int)(x) - 32)
# define TO_UPPER(x) ((unsigned int)(x) | 32)
# define IS_DIGIT(x) (TO_DIGIT(x) <= 9)
# define IS_ALPHA(x) (('A' <= (x) && (x) <= 'Z') || ('a' <= (x) && (x) <= 'z'))
# define IS_ALNUM(x)	(IS_DIGIT(x) || IS_ALPHA(x))
# ifndef MAX
#  define MAX(x, y) (x > y ? x : y)
# endif
# ifndef MIN
#  define MIN(x, y) (x < y ? x : y)
# endif
/*
** }}}
*/

/*
** https://stackoverflow.com/a/13546502 {{{
*/
# define	UT_MAXBSIZ(t) (((((sizeof(t) * 8)) * 1233) >> 12) + 1)
# define	ST_MAXBSIZ(t) (UT_MAXBSIZ(t) + (sizeof(t) == 8 ? 0 : 1))
# define	INT_BUFSIZE_BOUND(t) ((t)-1 < 0 ? ST_MAXBSIZ(t) : UT_MAXBSIZ(t))
/*
** }}}
*/

/*
** Long word copy {{{
*/
# define	ALIGNMENT_TEST(x) ((long)x & (sizeof(long) - 1))
# define	UNALIGNED(x, y) (ALIGNMENT_TEST(x) | ALIGNMENT_TEST(y))
# define	TOO_SMALL(len) ((len) < BIG_BLOCK_SIZE)
# define	_UNALIGNED(X) ((long)X % LITTLE_BLOCK_SIZE)
# define	BIG_BLOCK_SIZE (sizeof(long) << 2)
# define	LITTLE_BLOCK_SIZE (sizeof(long))
# define DETECT_NULL(X) (((X) - 0x0101010101010101) & ~(X) & 0x8080808080808080)
# define	DETECT_CHAR(X, MASK) (DETECT_NULL(X ^ MASK))
/*
** }}}
*/

/*
** Gcc function attributes {{{
*/
# ifdef TEST_INLINE
#  define FORCE_INLINE inline __attribute__((always_inline))
# else
#  define FORCE_INLINE
# endif
/*
** }}}
*/

#endif
