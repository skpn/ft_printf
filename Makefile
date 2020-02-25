# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 21:32:05 by sikpenou          #+#    #+#              #
#    Updated: 2020/02/25 15:16:40 by sikpenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = ft_printf

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_FILES =	\
			pf_core.c \
			pf_expand_numbers.c \
			pf_expand_text.c \
			pf_ft_printf.c \
			pf_padding.c \
			pf_parsing.c

SRC_DIR = srcs/

OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_DIR = objs/

INCLS = $(INC_DIR)

INC_DIR = includes/

LIB = $(addprefix $(LIB_DIR), libft.a)

LIB_INCLS = $(LIB_DIR)includes

LIB_SRCS = $(LIB_DIR)srcs

LIB_DIR = libft/

all: $(NAME)

$(NAME): $(INCLS) $(LIB_INCLS) $(LIB_SRCS) $(SRCS) $(LIB) Makefile
	@/bin/echo "make $(notdir $(NAME))"
	@rm -f auteur
	@echo sikpenou > auteur
	@mkdir -p $(OBJ_DIR)
	@make -j --no-print-directory objects
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJS) $(LIB)

$(LIB): FORCE
	@make -j --no-print-directory -C $(LIB_DIR)

objects: $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLS)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_INCLS) -o $@ -c $<

clean: FORCE
	@/bin/echo "make clean $(notdir $(NAME))"
	@rm -rf $(OBJ_DIR)
	@make clean -j --no-print-directory -C $(LIB_DIR)

fclean: clean
	@/bin/echo "make fclean $(notdir $(NAME))"
	@make fclean -j --no-print-directory -C $(LIB_DIR)
	@rm -f $(NAME)


re: FORCE
	@/bin/echo "make re $(notdir $(NAME))"
	@make -j --no-print-directory fclean
	@make -j --no-print-directory all

FORCE:

#.SILENT:
