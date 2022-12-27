# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:45:30 by ohanchak          #+#    #+#              #
#    Updated: 2022/12/27 16:16:45 by ohanchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SHELL=/bin/bash

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc
AR = ar rcs
SRC_DIR = srcs
INC_DIR = inc
SRCB_DIR = srcb
NAME = libftprintf.a
LIBFT = libft/libft.a

SRC = ft_printf.c			\
		ft_format.c			\
		ft_parse.c			\
		ft_print_chars.c		\
		ft_print_nbrs.c		\
		ft_print_hex.c

SRCB = ft_printf_bonus.c			\
		ft_format_bonus.c			\
		ft_parse_bonus.c			\
		ft_print_chars_bonus.c		\
		ft_print_nbrs_bonus.c		\
		ft_print_hex_bonus.c

OBJ = $(SRC):/%.o : $(SRC)/%.c

OBJB = $(SRCB):.c=.o

all: $(NAME)

$(NAME): create_dirs compile_libft
	@$(AR) $(NAME) $(OBJ)

/%.o: /%.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs compile_libft
	@$(AR) $(NAME) $(OBJB)

/%.o: /%.c
	@$(CC) $(CFLAGS) -c $< -o $@

compile_libft:
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/AlexHanchak/lib.git; \
	fi
	@make all -C libft
	@cp $(LIBFT) $(NAME)

clean:
	@if [ -d "libft" ]; then \
		make clean -C libft; \
	fi
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJB_DIR)
	
git:
	git add .
	git commit
	git push

re: fclean
	@make all


.PHONY: all clean fclean bonus re norminette compile_libft create_dirs test git