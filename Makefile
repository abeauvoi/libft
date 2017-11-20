# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 18:23:33 by abeauvoi          #+#    #+#              #
#    Updated: 2017/11/20 02:07:12 by abeauvoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
SRC_DIR	= src/
OBJ_DIR	= obj/
VPATH = $(SRC_DIR)
SRCS = $(addprefix $(SRC_DIR),ft_abs.c ft_atoi.c ft_atoi_skip.c \
			  ft_bzero.c ft_digittoint.c ft_delcontent.c ft_error.c \
			  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
			  ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_isxdigit.c \
			  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_lstiter.c \
			  ft_lstmap.c ft_lstsize.c ft_lststrsplit.c ft_lstpush.c \
			  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			  ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c ft_putchar.c \
			  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
			  ft_putnbr_base.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
			  ft_revstr.c ft_strcat.c ft_strchr.c ft_strchrnul.c ft_strclr.c \
			  ft_strcpy.c ft_strcmp.c ft_strdel.c ft_strdup.c ft_strequ.c \
			  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
			  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
			  ft_strncmp_no_case.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
			  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
			  ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c \
			  ft_print_int_tab_base.c ft_lstprint_base.c ft_strchrset.c \
			  ft_round.c ft_min.c ft_max.c ft_strrchr2.c ft_noccur.c \
			  ft_gen_swap.c ft_strchr2.c)
INC_DIR	= includes
INC = $(addprefix -I, $(INC_DIR))
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

## OUTPUT ####################################################################

GREEN		= \033[32m
RED			= \033[31m
LBLUE		= \033[36m
NC			= \033[0m

OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
OK_STRING=$(OK_COLOR)[OK]$(NC)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NC)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NC)

## RULES #######################################################################

all: obj_dir $(NAME)
	@true

$(NAME): msg $(OBJS)
	@echo "\r\033[J └── $(NAME) [$(GREEN)OK$(NC)]"
	@ar rc $@ $(filter-out $<,$^)
	@ranlib $@

$(OBJ_DIR)%.o: %.c
	@echo "\r\033[J └── $(NAME)[\\] > $<\c"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "\r\033[J └── $(NAME)[/] > $@\c"

msg:
	@echo "Creating:"

obj_dir:
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	
clean:
	@echo "$(NAME)\n └── \c"
	@$(RM) $(OBJS)
	@echo "$(RED)rm ./obj $(NC)[$(GREEN)OK$(NC)]"
	@rmdir $(OBJ_DIR) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME)
	@echo " └── \c"
	@echo "$(RED)rm $(NAME) $(NC)[$(GREEN)OK$(NC)]"

re: fclean all

show:
	@ar -t $(NAME)
nr:
	@echo "$(LBLUE)==== norminette ====$(NC)"
	@echo "norme for $(NAME)"
	@$	norminette $(SRC) > n.log
	@cat n.log | grep -B 1 'Error' | sed 's/--/  │└── end file /g' \
		| sed 's/Norme:/  ├┬─ NORME:/g' | sed 's/Error:/  │├── File :/g' \
		| sed 's/Error/  │├──/g' > enorm.log
	@echo "norm\t\t\c"
	@if test ! -s enorm.log; then echo "\t$(OK_STRING)"; \
		else echo "$(ERROR_STRING)" && cat enorm.log \
		&& echo "  │└── end file\n  └── end NORME"; fi;
	@$ rm -f n.log enorm.errors enorm.log

.PHONY: all clean fclean re msg show obj_dir
