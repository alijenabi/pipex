# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 16:57:21 by alijenabi         #+#    #+#              #
#    Updated: 2022/06/21 21:46:07 by alijenabi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC ?= gcc
CFLAGS ?= -Wall -Werror -Wextra
OFLAG ?= -O3

OBJDIR ?= build/
LIBFT_DIR ?= libft_init/
PRINTF_DIR ?= printf/
GNL_DIR ?= get_next_line/

HEADERS := 							 	\
	libft.h					 			\
	$(LIBFT_DIR)libft_init.h 			\
	$(LIBFT_DIR)ft_printf_extras.h 		\
	$(PRINTF_DIR)ft_printf.h			\
	$(PRINTF_DIR)ft_printf_helpers.h	\
	$(GNL_DIR)get_next_line.h

LIBFT_MSRC :=							\
	$(LIBFT_DIR)ft_atoi.c				\
	$(LIBFT_DIR)ft_bzero.c				\
	$(LIBFT_DIR)ft_calloc.c				\
	$(LIBFT_DIR)ft_isalnum.c			\
    $(LIBFT_DIR)ft_isalpha.c			\
	$(LIBFT_DIR)ft_isascii.c			\
	$(LIBFT_DIR)ft_isdigit.c			\
	$(LIBFT_DIR)ft_isprint.c			\
	$(LIBFT_DIR)ft_itoa.c				\
	$(LIBFT_DIR)ft_memchr.c				\
	$(LIBFT_DIR)ft_memcmp.c				\
	$(LIBFT_DIR)ft_memcpy.c				\
	$(LIBFT_DIR)ft_memmove.c			\
	$(LIBFT_DIR)ft_memset.c				\
	$(LIBFT_DIR)ft_putchar_fd.c			\
	$(LIBFT_DIR)ft_putendl_fd.c			\
	$(LIBFT_DIR)ft_putnbr_fd.c			\
	$(LIBFT_DIR)ft_putstr_fd.c			\
	$(LIBFT_DIR)ft_split.c				\
	$(LIBFT_DIR)ft_strchr.c				\
	$(LIBFT_DIR)ft_strdup.c				\
	$(LIBFT_DIR)ft_striteri.c			\
	$(LIBFT_DIR)ft_strjoin.c			\
	$(LIBFT_DIR)ft_strlcat.c			\
	$(LIBFT_DIR)ft_strlcpy.c			\
	$(LIBFT_DIR)ft_strlen.c				\
	$(LIBFT_DIR)ft_strmapi.c			\
	$(LIBFT_DIR)ft_strncmp.c			\
	$(LIBFT_DIR)ft_strnstr.c			\
	$(LIBFT_DIR)ft_strrchr.c			\
	$(LIBFT_DIR)ft_strtrim.c			\
	$(LIBFT_DIR)ft_substr.c				\
	$(LIBFT_DIR)ft_tolower.c			\
	$(LIBFT_DIR)ft_toupper.c

LIBFT_LIST_SRC :=					\
	$(LIBFT_DIR)ft_lstadd_back.c	\
	$(LIBFT_DIR)ft_lstadd_front.c	\
	$(LIBFT_DIR)ft_lstclear.c		\
	$(LIBFT_DIR)ft_lstdelone.c		\
	$(LIBFT_DIR)ft_lstiter.c		\
	$(LIBFT_DIR)ft_lstlast.c		\
	$(LIBFT_DIR)ft_lstmap.c			\
	$(LIBFT_DIR)ft_lstnew.c			\
	$(LIBFT_DIR)ft_lstsize.c

LIBFT_PRINTF_EXTRAS_SRC := 				\
	$(LIBFT_DIR)ft_str_tolower.c		\
	$(LIBFT_DIR)ft_str_toupper.c		\
	$(LIBFT_DIR)ft_strinv.c				\
	$(LIBFT_DIR)ft_ulong_to_str.c

PRINTF_SRC := 							\
	$(PRINTF_DIR)ft_printf.c 			\
	$(PRINTF_DIR)ft_printf_if_char.c 	\
	$(PRINTF_DIR)ft_printf_if_null.c 	\
	$(PRINTF_DIR)ft_printf_if_number.c 	\
	$(PRINTF_DIR)ft_printf_if_pointer.c \
	$(PRINTF_DIR)ft_printf_if_string.c

GNL_SRC := 							\
	$(GNL_DIR)get_next_line.c 			\
	$(GNL_DIR)get_next_line_utils.c

LIBFT_SRC := $(LIBFT_MSRC) $(LIBFT_LIST_SRC) $(LIBFT_PRINTF_EXTRAS_SRC)

SRC := $(LIBFT_SRC) $(PRINTF_SRC) $(GNL_SRC)

OBJS = ${SRC:.c=.o}

OBJECTS_PREF := $(addprefix $(OBJDIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJECTS_PREF)
	@ar rcs $(NAME) $(OBJECTS_PREF)

clean: 
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJDIR)%.o : %.c libft.h
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)$(LIBFT_DIR)
	@mkdir -p $(OBJDIR)$(PRINTF_DIR)
	@mkdir -p $(OBJDIR)$(GNL_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(OFLAG)			

norm: norm_h norm_m

norm_h:
	@norminette $(HEADERS)

norm_m: 
	@norminette $(SRC)

.PHONY: all clean fclean re bonus norm
