/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:16:14 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/24 07:36:14 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Includes {{{
*/

# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <wchar.h>
# include "libft.h"

/*
** }}}
*/

/*
** Defines {{{1
*/
# define PREFIXES "-+   0X0x0b"
# define SPECIFIERS "bcCdDioprsSuUxX"
# define FLAGMASK (ALT | ZERO_PAD | LEFT_ADJ | SPACE | PLUS_SIGN | THOUSEP)
# define FT_PRINTF_BUFSZ 8192
# define NEED_PADDING 2
# define S(x) [(x) - 'A']

/*
** Powers of 10 {{{2
*/
# define	P01 10ull
# define	P02 100ull
# define	P03 1000ull
# define	P04 10000ull
# define	P05 100000ull
# define	P06 1000000ull
# define	P07 10000000ull
# define	P08 100000000ull
# define	P09 1000000000ull
# define	P10 10000000000ull
# define	P11 100000000000ull
# define	P12 1000000000000ull
/*
** 2}}}
*/

/*
** Powers of 16 {{{2
*/
# define	POW_16_X(pow10)	0x ## pow10
# define	POW_16(pow10)	POW_16_X(pow10)
/*
** 2}}}
*/

/*
** Powers of 8 {{{2
*/
# define	POW_8_X(pow10)	0 ## pow10
# define	POW_8(pow10)	POW_8_X(pow10)
/*
** 2}}}
*/
/*
** Powers of 2 {{{2
*/
# define	POW_2(exp) (1U << exp)
/*
** 2}}}
*/
/*
** 1}}}
*/

/*
** Type definitions {{{
*/

enum 				e_flags
{
	ALT			= (1U << ('#' - ' ')),
	ZERO_PAD 	= (1U << ('0' - ' ')),
	LEFT_ADJ 	= (1U << ('-' - ' ')),
	SPACE		= (1U << (' ' - ' ')),
	PLUS_SIGN	= (1U << ('+' - ' ')),
	THOUSEP 	= (1U << ('\'' - ' '))
};

union 				u_arg
{
	uintmax_t i;
	long double f;
	void *p;
};

union 				u_redir
{
	int 	fd;
	char 	*buf;
};

typedef struct 		s_ftpf
{
	char 			*workptr;
	char 			*endptr;
	char 			*dup_fmt;
	char 			pad_char;
	uint32_t 		flags;
	uint32_t 		width;
	int 			prec;
	int				len;
	union u_arg 	arg;
	int 			done;
	char 			buf[FT_PRINTF_BUFSZ + 1] __attribute__ ((aligned (8)));
	size_t			bufpos;
	char			convbuf[INT_BUFSIZE_BOUND(uintmax_t)];
	const char 		*prefix;
	int 			prefix_len;
	wchar_t 		wchar[2];
	union u_redir 	redir;
	size_t 			redir_bufsz;
	va_list			ap;
	int 			(*outf)(struct s_ftpf *);
} 					t_ftpf;

enum				e_ftpf_states
{
	BARE, LPRE, LLPRE, HPRE, HHPRE, ZTPRE, JPRE, STOP, PTR, INT, UINT,
	ULLONG, LONG, ULONG, SHORT, USHORT, CHAR, UCHAR, NOARG, MAXSTATE
};

# define LLONG ULLONG
# define SIZET ULONG
# define IMAX ULONG
# define UMAX ULLONG
# define PDIFF LONG
# define UIPTR ULONG

/*
**}}}
*/

/*
** Function declarations {{{1
*/

/*
** Tells gcc that these functions behave like printf
*/
# define 	TYPE_PRINTF(x, y) int __attribute__((format (printf, x, y)))

TYPE_PRINTF(1, 2)	ft_printf(const char *format, ...);
TYPE_PRINTF(2, 3)	ft_sprintf(char *str, const char *format, ...);
TYPE_PRINTF(3, 4)	ft_snprintf(char *str, size_t size, const char *fmt, ...);
TYPE_PRINTF(2, 3)	ft_asprintf(char **ret, const char *fmt, ...);
TYPE_PRINTF(2, 3)	ft_dprintf(int fd, const char *fmt, ...);

TYPE_PRINTF(1, 0)	ft_vprintf(const char *format, va_list ap);
TYPE_PRINTF(2, 0)	ft_vsprintf(char *str, const char *format, va_list ap);
TYPE_PRINTF(3, 0)	ft_vsnprintf(char *str, size_t size, const char *fmt,
		va_list ap);
TYPE_PRINTF(2, 0)	ft_vasprintf(char **ret, const char *fmt, va_list ap);
TYPE_PRINTF(2, 0)	ft_vdprintf(int fd, const char *fmt, va_list ap);
/*
** Internal functions {{{2
*/
int					ft_printf_core(t_ftpf *info, va_list ap);

uint32_t			parse_flags(t_ftpf *info);
uint32_t			parse_field_width(t_ftpf *info, va_list ap);
int					parse_precision(t_ftpf *info, va_list ap);
void				parse_size_modifiers(t_ftpf *info);

void				access_branch_table(t_ftpf *info);

int 				handle_bin_int(t_ftpf *info);
int 				handle_dec_int(t_ftpf *info);
int 				handle_dec_uint(t_ftpf *info);
int 				handle_char(t_ftpf *info);
int 				handle_wchar(t_ftpf *info);
int 				handle_oct_int(t_ftpf *info);
int 				handle_hex_int(t_ftpf *info);
int 				handle_hex_str(t_ftpf *info);
int 				handle_str(t_ftpf *info);
int 				handle_wstr(t_ftpf *info);

int					ft_atoi_skip(const char **str);
void				pad_buffer(uint32_t width, int32_t prec, int32_t flags,
		t_ftpf *info);
int					is_utf8(uint32_t wc);
int					ft_wchar_to_utf8(char *s, wchar_t wchar);

int 				out_fd(t_ftpf *info);
int 				out_str(t_ftpf *info);

size_t 				ft_u64toa_b16(uint64_t num, char *dest, uint16_t locase);
size_t				ft_u64toa_b10(uint64_t num, char *dest);
size_t 				ft_u64toa_b8(uint64_t num, char *dest);

void				get_arg(union u_arg *arg, int32_t type, va_list ap);

/*
** 2}}}
*/
/*
** 1}}}
*/

/*
** Old ft_printf header {{{
*/

# if 0
/*
** Reduced pointer names
*

# define WIDTH spec->width
# define PREC spec->prec
# define FLAGS spec->flags
# define SIZE spec->size

/*
** Digits
*/

# define UPPER_DIGITS	"0123456789ABCDEF"

/*
** Get_value modes
*/

# define SIGNED 0
# define UNSIGNED 1

/*
** Color tags
*/

# define CA "{eoc}0{bold}1{uline}4{blink}5{hl}7{hidden}8{rbold}21{ruline}24"
# define CB "{rblink}25{rhl}27{rhidden}28{black}30{red}31{green}32{yellow}33"
# define CC "{blue}34{pink}35{cyan}36{white}37{bblack}40{bred}41{bgreen}42"
# define CD "{byellow}43{bblue}44{bpink}45{bcyan}46{bwhite}47"
# define COLOR_TABLE CA CB CC CD

/*
** Typedefs
*/

typedef enum				e_step
{
	CONTINUE,
	END_OF_CONVERSION,
	OUT_OF_SCOPE,
	END_OF_FORMAT,
	DATA_IS_NULL
}							t_step;

typedef enum				e_status
{
	FAILURE = -1,
	SUCCESS
}							t_status;

enum
{
	COLOR_CODE_SIZE = 6,
	COLORS = 21,
	MAX_NDIGITS = 64,
	BUF_SIZE = 1024
}							e_limits;

typedef enum				e_ftpf_radix
{
	BIN = 2,
	OCT = 8,
	DEC = 10,
	HEX = 16
}							t_ftpf_radix;

typedef enum				e_ftpf_size
{
	IS_CHAR,
	IS_SHORT,
	IS_INT,
	IS_LONG,
	IS_LONG_DOUBLE,
	IS_SIZE_T,
	IS_INTMAX,
	SIZES
}							t_ftpf_size;

typedef enum				e_ftpf_flag
{
	ZERO = 0x0001,
	SIGN = 0x0002,
	ALT = 0x0004,
	SPACE = 0x0008,
	LEFT = 0x0010,
	UPPER = 0x0020,
	GROUP = 0x0040
}							t_ftpf_flag;

typedef int					t_wchar;
typedef	unsigned char		t_uc;

typedef struct				s_ftpf
{
	t_ftpf_size		size;
	t_ftpf_flag		flags;
	int				prec;
	int				width;
}							t_ftpf;

typedef struct				s_ftpf_buf
{
	char	start[BUF_SIZE + 1];
	char	*current;
	char	*end;
	int		fd;
	int		done;
}							t_ftpf_buf;

typedef t_step				(*t_ftpf_parser)(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
typedef void				(*t_ftpf_get_val)(va_list *ap, t_uc mode,
		void *data);

/*
** Definitions
*/

int							ft_printf(const char *format, ...);
int							ft_printf_core(const char *format, va_list *ap);

/*
** Conversion parser functions
*/

t_step						parse_one_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						colors(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						space_flag(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						unknown_form(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						alt_flag(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						percent_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						group_flag(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						get_width(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						sign_flag(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						left_flag(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						get_precision(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						zero_flag(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						get_width(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						char_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						integer_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						long_double_mod(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						octal_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						string_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						hex_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						binary_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						half_mod(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						intmax_mod(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						long_mod(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						number_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						pointer_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						non_printable_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						string_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						unsigned_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						fd_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						hex_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						size_mod(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);
t_step						float_spec(const char **format, va_list *ap,
		t_ftpf *spec, t_ftpf_buf *buffer);

/*
** Argument retrieval
*/

void						get_value(va_list *ap, t_ftpf_size size,
		void *data, t_uc mode);
void						arg_is_int(va_list *ap, t_uc mode, void *data);
void						arg_is_size(va_list *ap, t_uc mode, void *data);
void						arg_is_intmax(va_list *ap, t_uc mode, void *data);

/*
** Utilities
*/

size_t						ftpf_itoa(uintmax_t nb, char *str, t_uc radix,
		const char *digits);
size_t						ftpf_ftoa(long double val, char *str, int prec);
void						init_buffer(t_ftpf_buf *buffer);
size_t						ft_wcslen(const t_wchar *s);
size_t						ft_wchar_bc(t_wchar ch);
size_t						ft_wcs_bc(const t_wchar *s, int prec);
void						wchar_to_utf8(t_ftpf_buf *buffer, t_wchar ch);
int							atoi_skip(const char **format);
void						copy_to_buf(t_ftpf_buf *buffer, const char ch);
void						safe_ft_strncpy(t_ftpf_buf *buffer,
		const char *src, ssize_t len);
void						padding(t_ftpf_buf *buffer, int stat,
		char pad_char);
char						*ft_strstrn(const char *big, const char *little,
		size_t n);
char						get_sign(intmax_t nb, t_ftpf_flag flags);
void						print_null(t_ftpf *spec, t_ftpf_buf *buffer);
void						flush_buffer(t_ftpf_buf *buffer, size_t len);
bool						ft_iswprint(t_wchar wc);
# endif

/*
**}}}
*/

#endif
