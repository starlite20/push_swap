#ifndef PUSH_SWAP
#define PUSH_SWAP

#include<stdlib.h>

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
void stack_init(t_stack *stack);
void stack_push(t_stack *stack, int value);
int stack_pop(t_stack *stack);
void stack_print(t_stack *stack);


//i wont be needing this right? as i have the size updated on the structure always...?	
//int stack_size(t_stack *stack);



#endif