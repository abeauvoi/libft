# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 18:23:33 by abeauvoi          #+#    #+#              #
#    Updated: 2020/02/14 15:43:41 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#
# Directories
#

INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
VPATH = $(addprefix $(SRC_DIR)/,alloc conv char_classes lst math mem misc put \
	str redo_printf $(addprefix redo_printf/, buffering_and_output \
	core ft_u64toa handlers parsing wrappers))

#
# Sources
#

ALLOC = ft_realloc.c

CHAR_SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
	    ft_isprint.c ft_isspace.c ft_isupper.c ft_isxdigit.c ft_isblank.c \
	    ft_isdigit_str.c ft_isalnum_str.c 

CONV_SRCS = ft_atoi.c ft_atoi_skip.c ft_digittoint.c ft_xdigittoint.c \
	    ft_tolower.c ft_toupper.c

OLD_PRINTF_SRCS = buffer.c char_spec.c colors.c cvt_number.c fd_spec.c \
		  flags.c ft_iswprint.c ft_printf.c ft_printf_core.c \
		  ft_strstrn.c ft_wcslen.c get_precision.c get_value.c \
		  get_value_bis.c get_width.c group_flag.c hex_spec.c \
		  integer_spec.c non_printable_spec.c octal_spec.c \
		  parse_one_spec.c percent_spec.c pointer_spec.c \
		  print_null.c safe_ft_strncpy.c size_mod.c string_spec.c \
		  unknown_form.c unsigned_spec.c utils.c atoi_skip.c \
		  binary_spec.c 

LST_SRCS = ft_delcontent.c  ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	   ft_lstnew.c ft_lstiter.c ft_lstmap.c ft_lstsize.c \
	   ft_lstpush.c

MATH_SRCS = ft_abs.c ft_pow.c ft_round.c ft_min.c ft_max.c ft_ispow2.c \
	    ft_nbrlen_b10.c ft_nbrlen_b16.c ft_nbrlen_b8.c 

MEM_SRCS = ft_memalloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	   ft_memmove.c ft_memset.c

MISC_SRCS = ft_insn_shrui.c ft_haschar.c ft_haszero.c ft_isaligned.c \
	    ft_swap_any.c ft_swap_int.c get_next_line.c

PUT_SRCS = ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	   ft_putnbr.c ft_putnbr_base.c ft_putnbr_fd.c ft_putstr.c \
	   ft_putstr_fd.c

REDO_PRINTF_SRCS = buffering.c output.c branch_table.c ft_printf_core.c \
		   utils.c va_arg.c ft_u64toa_b10.c ft_u64toa_b16.c \
		   ft_u64toa_b2.c ft_u64toa_b8.c handle_binary.c \
		   handle_char.c handle_decimal.c handle_hexadecimal.c \
		   handle_octal.c handle_padding.c handle_percent.c \
		   handle_string.c colors.c parsing.c va_list_wrappers.c \
		   wrappers.c

STR_SRCS = ft_bzero.c ft_revstr.c ft_strcat.c ft_strchr.c \
	   ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strdup2.c \
	   ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoin2.c \
	   ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	   ft_strncmp_icase.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	   ft_strnoccur.c ft_strnstr.c ft_strnstr_icase.c ft_strrchr.c \
	   ft_strrchr2.c ft_strsplit.c ft_strsplitset.c ft_strstr.c \
	   ft_strsub.c ft_strtrim.c

SRCS = $(CHAR_SRCS) $(CONV_SRCS) $(REDO_PRINTF_SRCS) $(LST_SRCS) $(MATH_SRCS) \
		  $(MEM_SRCS) $(MISC_SRCS) $(PUT_SRCS) $(STR_SRCS)

#
# Build
#

CC = gcc
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
COMP = $(CC) $(CFLAGS) -o $@ -c $<
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
BUILD_LIB = ar -rcs $@ $^

#
# Rules
#

all: $(NAME)

debug: CFLAGS += -fsanitize=address -g3
debug: re

$(NAME): $(OBJS)
	@$(BUILD_LIB) && echo "Library created"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(COMP)

clean:
	$(RM) $(OBJS)
	@rmdir $(OBJ_DIR) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME)

re: fclean
re: all

show:
	@ar -t $(NAME)

.PHONY: all clean fclean re show
