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

//functions for linkedlist creation
t_node *create_node(int value);
t_stack *stack_init();
void stack_push(t_stack *stack, int value);
void stack_push_back(t_stack *stack, int value);
int stack_pop(t_stack *stack);
void stack_print(t_stack *stack);
void stack_clear(t_stack **stack);


void ft_puterr_exit(char *str);

#endif