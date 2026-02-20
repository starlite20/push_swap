#include "../../push_swap.h"

void stack_push(t_stack *stack, int value)
{
	t_node *tail;
	t_node *newnode = create_node(value);
	if(!newnode)
		return ;

	if(stack->head == NULL)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
	}
	else
	{
		tail = stack->head->prev;

		newnode->next = stack->head;
		newnode->prev = tail;

		tail->next = newnode;
		stack->head->prev = newnode;
	}
	stack->head = newnode;
	stack->size += 1;
}
