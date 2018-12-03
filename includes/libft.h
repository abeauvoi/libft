/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:54:46 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/01 14:54:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include "get_next_line.h"

/*
** Defines {{{
*/
# define XDIGITS_UPCASE "0123456789ABCDEF"

/*
** }}}
*/

/*
** Typedefs {{{
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_str
{
	char	*s;
	size_t	len;
}				t_str;
/*
** }}}
*/

/*
** src/alloc {{{
*/
void		*ft_realloc(void *ptr, size_t size);
/*
** }}}
*/

/*
** src/char_classes {{{
*/
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isblank(char c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
int			ft_isprint(int c);
int			ft_isxdigit(int c);
int			ft_isalnum_str(const char *s);
int			ft_isalnum_nstr(const char *s, size_t n);
int			ft_isdigit_str(const char *s);
int			ft_isdigit_nstr(const char *s, size_t n);
/*
** }}}
*/

/*
** src/conv {{{
*/
int			ft_atoi(const char *s);
int			ft_atoi_skip(const char **s);
uint8_t		ft_digittoint(char c);
uint8_t		ft_todigit(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_xdigittoint(char c);
/*
** }}}
*/

/*
** src/lst {{{
*/
void		ft_delcontent(void *content, size_t __attribute__((unused)) size);
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstnew(void *content, size_t content_size);
void		ft_lstiter(t_list *list, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));
void		ft_lstpush(t_list **alst, t_list *new);
size_t		ft_lstsize(t_list *list);
void		ft_lstprint_base(t_list *list, uint8_t sz_elem, uint8_t radix);
/*
** }}}
*/

/*
** src/math {{{
*/
uint64_t	ft_pow(int value, uint32_t exponent);
int64_t		ft_abs(int64_t value);
int64_t		ft_round(double db);
int64_t		ft_min(int64_t a, int64_t b);
int64_t		ft_max(int64_t a, int64_t b);
bool		ft_ispow2(uint64_t x);
uint8_t		ft_nbrlen_b10(uint64_t val);
uint8_t		ft_nbrlen_b16(uint64_t val);
uint8_t		ft_nbrlen_b8(uint64_t val);
/*
** }}}
*/

/*
** src/mem {{{
*/
void		*ft_memalloc(size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t count);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t count);
void		*ft_memset(void *dst, int c, size_t n);
/*
** }}}
*/

/*
** src/misc {{{
*/
void		ft_swap_int(int *a, int *b);
void		ft_swap_any(void *a, void *b, size_t size_of);
uint64_t	ft_insn_shrui(uint8_t vec[8], uint8_t shift);
uint64_t 	ft_haszero(uint64_t word);
uint64_t	ft_haschar(uint64_t word, uint64_t mask);
bool		ft_isaligned(const void *ptr, uint8_t align_sz);
/*
** }}}
*/

/*
** src/put {{{
*/
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(int nb);
void		ft_putnbr_base(int64_t nb, uint8_t b);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(char const *str);
void		ft_putstr_fd(char const *s, int fd);
void		ft_print_int_tab_base(void *data, uint8_t size_of, size_t len,
		uint8_t radix);
/*
** }}}
*/

/*
** src/str {{{
*/
void		ft_bzero(void *str, size_t count);
void		ft_revstr(char *s);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strchrnul(const char *s, int c);
void		ft_strclr(char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strdup2(const char *s1, size_t len_s1);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin2(char const *s1, char const *s2, size_t l1, size_t l2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsz);
size_t		ft_strlen(const char *str);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmap2(char const *s, char (*f)(char), size_t n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *dst, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strncmp_icase(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(char const *s, char c);
char		**ft_strsplitset(char const *s, char const *delims);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strsub(char const *s, uint32_t start, size_t len);
char		*ft_strtrim(char const *s);
char		*ft_strchrset(const char *s, const char *charset);
int			ft_strrchr2(const char *const str, char c, size_t lenstr);
int			ft_strchr2(const char *const str, char c);
uint32_t	ft_strnoccur(const char *s, const char c);
/*
** }}}
*/

#endif
