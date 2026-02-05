# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 20:59:35 by ssujaude          #+#    #+#              #
#    Updated: 2026/02/05 21:14:21 by ssujaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

RM = rm -f

AR = ar rcs

SRCS = \
	ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c \
	ft_isdigit.c  ft_isprint.c  ft_itoa.c  ft_memchr.c  ft_memcmp.c \
	ft_memcpy.c  ft_memmove.c  ft_memset.c  ft_putchar_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c \
	ft_putstr_fd.c  ft_split.c  ft_strchr.c  ft_strdup.c  ft_striteri.c  ft_strjoin.c \
	ft_strlcat.c  ft_strlcpy.c  ft_strlen.c  ft_strmapi.c  ft_strncmp.c  ft_strnstr.c \
	ft_strrchr.c  ft_strtrim.c  ft_substr.c  ft_tolower.c  ft_toupper.c 

BONUS = \
	ft_lstadd_back.c  ft_lstadd_front.c  ft_lstclear.c  ft_lstdelone.c  ft_lstiter.c  ft_lstlast.c \
	ft_lstmap.c  ft_lstnew.c  ft_lstsize.c

PRINTF = \
	ft_printf.c ft_flag_mgr.c ft_print_num.c ft_print_num_utils.c \
	ft_print_hex.c ft_print_unum.c ft_print_addr.c ft_print_chars.c ft_print_strs.c 

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}
PRINTF_OBJS = ${PRINTF:.c=.o}

all: $(NAME)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${OBJS} ${BONUS_OBJS} ${PRINTF_OBJS}
	$(AR) ${NAME} $(OBJS) ${BONUS_OBJS} ${PRINTF_OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS} ${PRINTF_OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 