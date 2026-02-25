/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:01:38 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/25 23:30:40 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

void				ft_puterr_exit(void);
long long			ft_atoll(const char *str, int *error);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
int					ft_abs(int num);
int					ft_is_just_number(char *str);

int					validate_and_store(t_stack *numList, int count,
						char **input);
void				free_splitted_str(char **splitted_str);
int					process_and_store_num(t_stack *numList, char *str);
int					process_splitted_str(char **splitted_str, t_stack *numList);
void				error_exit(t_stack *stack_a, t_stack *stack_b);

t_node				*create_node(int value);
t_stack				*stack_init(void);
void				stack_push(t_stack *stack, int value);
int					stack_push_back(t_stack *stack, int value);
int					stack_pop(t_stack *stack);
void				stack_print(t_stack *stack);
void				stack_clear(t_stack **stack);
t_node				*stack_find_node(t_stack *stack, int value);
int					stack_node_distance(t_stack *stack, t_node *node);
t_node				*stack_find_min(t_stack *stack);
t_node				*stack_find_max(t_stack *stack);
void				stack_rotate_till_reached(t_stack *stack, char stack_id,
						t_node *node_to_be_head);
int					stack_node_is_forward(t_stack *stack, t_node *node);
int					is_sorted_stack(t_stack *numList);

void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);

void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);

void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);

void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

void				sort_stack(t_stack *a, t_stack *b);
void				sort_three(t_stack *numStack);
void				sort_five(t_stack *a, t_stack *b);

t_node				*find_spot_in_a(t_stack *a, int value_to_push);
t_node				*find_spot_in_b(t_stack *b, int value_to_push);
void				rotate_and_move(t_stack *a, t_stack *b,
						t_node *node_to_push_from_a);
void				update_min_node(t_node **min_cost_node, int *min_cost,
						t_node *cur, int cost);
t_node				*find_cheapest_node(t_stack *a, t_stack *b,
						int nodes_traversed);
void				turk_sort(t_stack *a, t_stack *b);

#endif