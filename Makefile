# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 14:03:22 by alijenabi         #+#    #+#              #
#    Updated: 2022/07/10 00:11:36 by alijenabi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC     ?= gcc
CFLAGS ?= -Wall -Werror -Wextra

OBJ_DIR       ?= build/
LIBFT_DIR     ?= libft/
LOG_DIR       ?= log/
STACK_DIR     ?= stack/

LIBFT := $(LIBFT_DIR)libft.a

HEADERS := \
	$(LOG_DIR)logger.h \
	$(STACK_DIR)stack.h \
	$(STACK_DIR)stack_operation.h \
	$(STACK_DIR)stack_pair.h \
	$(STACK_DIR)stack_pair_operation.h \
	$(STACK_DIR)stack_tree.h \
	$(STACK_DIR)stack_types.h \

SOURCES := \
	main.c \
	$(LOG_DIR)logger.c \
	$(LOG_DIR)logger_setup.c \
	$(STACK_DIR)stack.c \
	$(STACK_DIR)stack_operation.c \
	$(STACK_DIR)stack_operation_push.c \
	$(STACK_DIR)stack_pair_operation.c \
	$(STACK_DIR)stack_pair_operation_push.c \
	$(STACK_DIR)stack_pair_operation_reverse_rotate.c \
	$(STACK_DIR)stack_pair_operation_rotate.c \
	$(STACK_DIR)stack_pair_operation_swap.c \
	$(STACK_DIR)stack_pair.c \
	$(STACK_DIR)stack_tree.c \

OBJS = ${SOURCES:.c=.o}
OBJECTS_PREF := $(addprefix $(OBJ_DIR), $(OBJS))

all: libft $(NAME)

$(NAME): $(OBJECTS_PREF)
	$(CC) $(OBJECTS_PREF) $(MLX) $(LIBFT) -o $(NAME)

libft:
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(LOG_DIR)
	@mkdir -p $(OBJ_DIR)$(STACK_DIR)
	$(CC) -g $(CFLAGS) -c $< -o $@

norm:
	@norminette $(HEADERS)
	@norminette $(SOURCES)

.PHONY: all libft mlx clean fclean re norm
