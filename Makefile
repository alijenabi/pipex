# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 14:03:22 by alijenabi         #+#    #+#              #
#    Updated: 2022/07/06 00:54:29 by alijenabi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC     ?= gcc
CFLAGS ?= -Wall -Werror -Wextra

OBJ_DIR       ?= build/
LIBFT_DIR     ?= libft/
LOG_DIR       ?= log/
PROCESS_DIR   ?= process/
SYSTEM_DIR    ?= system/

LIBFT := $(LIBFT_DIR)libft.a

HEADERS := \
	$(LOG_DIR)logger.h \
	$(PROCESS_DIR)processor.h \
	$(SYSTEM_DIR)inout.h \
	$(SYSTEM_DIR)pipe.h \
	$(SYSTEM_DIR)environment.h \

SOURCES := \
	main.c \
	$(LOG_DIR)logger.c \
	$(LOG_DIR)logger_setup.c \
	$(PROCESS_DIR)ft_fork.c \
	$(PROCESS_DIR)processor.c \
	$(SYSTEM_DIR)inout.c \
	$(SYSTEM_DIR)pipe.c \
	$(SYSTEM_DIR)environment.c \

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
	@mkdir -p $(OBJ_DIR)$(PROCESS_DIR)
	@mkdir -p $(OBJ_DIR)$(SYSTEM_DIR)
	$(CC) -g $(CFLAGS) -c $< -o $@

norm:
	@norminette $(HEADERS)
	@norminette $(SOURCES)

.PHONY: all libft mlx clean fclean re norm
