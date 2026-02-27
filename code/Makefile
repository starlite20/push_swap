# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 19:14:16 by ssujaude          #+#    #+#              #
#    Updated: 2026/02/28 02:58:31 by ssujaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

MAKE = make -C
RM = rm -f


EXPANDED_LIBFT = \
	utils/expanded_libft/ft_abs.c utils/expanded_libft/ft_atoll.c utils/expanded_libft/ft_is_just_number.c \
	utils/expanded_libft/ft_max.c utils/expanded_libft/ft_min.c utils/expanded_libft/ft_puterr_exit.c

CIRC_LIST = \
	utils/circ_list/create_node.c utils/circ_list/stack_clear.c utils/circ_list/stack_find_max.c \
	utils/circ_list/stack_find_min.c utils/circ_list/stack_find_node.c utils/circ_list/stack_init.c \
	utils/circ_list/stack_node_distance.c utils/circ_list/stack_node_is_forward.c utils/circ_list/stack_pop.c \
	utils/circ_list/stack_print.c utils/circ_list/stack_push_back.c utils/circ_list/stack_push.c \
	utils/circ_list/stack_rotate_till_reached.c

RULES = \
	utils/rules/push.c utils/rules/rev_rotate.c utils/rules/rotate.c utils/rules/swap.c \
	utils/rules_checker/push.c utils/rules_checker/rev_rotate.c utils/rules_checker/rotate.c utils/rules_checker/swap.c

SORT_ALGORITHM = \
	utils/sort_algorithm/is_sorted_stack.c utils/sort_algorithm/sort_five.c utils/sort_algorithm/sort_stack.c \
	utils/sort_algorithm/sort_three.c utils/sort_algorithm/turk_sort.c utils/sort_algorithm/turk_sort_support.c

UTILS = utils/input_validator.c \
	$(EXPANDED_LIBFT) $(CIRC_LIST) $(RULES) $(SORT_ALGORITHM) 

BONUS_UTILS = $(UTILS) \
	utils/checker_utils/read_and_run.c utils/checker_utils/run_instruction.c 

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

SRCS = push_swap.c $(UTILS)
BONUS_SRCS = checker.c $(BONUS_UTILS)

OBJS = ${SRCS:.c=.o} 
BONUS_OBJS = ${BONUS_SRCS:.c=.o} 


all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} ${LIBFT_PATH}
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	${MAKE} ${LIBFT_PATH}
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	
.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${MAKE} ${LIBFT_PATH} clean
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${OBJS} ${BONUS_OBJS}
	${RM} ${NAME} ${BONUS_NAME}


re: fclean all

.PHONY: all clean fclean re bonus