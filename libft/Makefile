# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skpn <skpn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 21:32:05 by sikpenou          #+#    #+#              #
#    Updated: 2020/02/11 10:44:35 by skpn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = libft.a

SRCS = $(addprefix $(SRCDIR), $(SRCFILES))

SRCFILES = \
			easymalloc.c \
			ft_abs.c \
			ft_atoi.c \
			ft_atoi_base.c \
			ft_check_base.c \
			ft_convert_base.c \
			ft_find_next_prime.c \
			ft_free.c \
			ft_ischarset.c \
			ft_isspace.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lltoa_base.c \
			ft_lstadd.c \
			ft_lstadd_sorted.c \
			ft_lstadd_back.c \
			ft_lstadd_back_new.c \
			ft_lstadd_new.c \
			ft_lstcpy.c \
			ft_lstcycle.c \
			ft_lstfind.c \
			ft_lstfree.c \
			ft_lstfree_elem.c \
			ft_lstfree_head.c \
			ft_lstjoin.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstnew_elem.c \
			ft_lstnew_head.c \
			ft_lstpop.c \
			ft_lstpop_elem.c \
			ft_lstprint.c \
			ft_max.c \
			ft_memalloc.c \
			ft_memchr.c \
			ft_memchr_pos.c \
			ft_memcmp.c \
			ft_memcpy_heap.c \
			ft_memmove.c \
			ft_memset.c \
			ft_memset_pattern.c \
			ft_min.c \
			ft_pow.c \
			ft_putnbr.c \
			ft_realloc.c \
			ft_strchr_pos.c \
			ft_strcmp_heap.c \
			ft_strcpy.c \
			ft_strcpy_heap.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strlen.c \
			ft_strlen_heap.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_swap.c \
			ft_ulltoa.c \
			ft_ulltoa_base.c \
			hash_tables_memory.c \
			hash_tables_access.c \
			hash_tables_insert.c \
			hash_tables_display.c \
			dynamic_array.c		\
			lib_errors.c

SRCDIR = srcs/

OBJS = $(addprefix $(OBJDIR), $(OBJFILES))

OBJFILES = $(SRCFILES:.c=.o)

OBJDIR = objs/

INCLS = $(INCLDIR)libft.h

INCLDIR = includes/

all: $(NAME)

$(NAME): $(INCLS) $(SRCS) Makefile
	@/bin/echo make $(NAME)
	@rm -f auteur
	@mkdir -p $(OBJDIR)
	@make -j --no-print-directory objects
	@ar sr $(NAME) $(OBJS)
	@ranlib $(NAME)

objects: $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLS)
	@$(CC) $(CFLAGS) -I $(INCLDIR) -o $@ -c $<

clean: FORCE
	@rm -rf $(OBJDIR)
	@echo "rm -f .o files"

fclean: clean
	@rm -f a.out
	@rm -f test
	rm -f $(NAME)

re: FORCE
	@make -j --no-print-directory fclean
	@make -j --no-print-directory all

FORCE:

#.SILENT:
