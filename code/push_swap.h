#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdlib.h>
#include "libft/libft.h"


typedef struct s_node{
	int value;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack{
	t_node *head;
	int size;
} t_stack;


//expanded libft
void ft_puterr_exit(char *str);
long long ft_atoll(const char *str);

//functions for linkedlist
t_node *create_node(int value);
t_stack *stack_init();
void stack_push(t_stack *stack, int value);
void stack_push_back(t_stack *stack, int value);
int stack_pop(t_stack *stack);
void stack_print(t_stack *stack);
void stack_clear(t_stack **stack);
t_node *stack_find_node(t_stack *stack, int value);
int stack_node_distance(t_stack *stack, t_node *node);
t_node *stack_find_min(t_stack *stack);
void stack_rotate_till_reached(t_stack *stack, t_node *node_to_be_head);


//operations
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);

void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);

void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);

void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);

//the sorts
void sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *numStack);
void	sort_five(t_stack *a, t_stack *b);
// void	large_sort(t_stack *numStack);

#endif