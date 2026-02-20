#include "../../push_swap.h"

int stack_pop(t_stack *stack)
{
	int value;
	t_node *node_to_pop;
	t_node *tail;

	node_to_pop = stack->head;

	if(!node_to_pop)
	{
		ft_puterr_exit("Error: Attempting to Pop an Empty Stack");
	}

	value = node_to_pop->value;

	if(stack->size == 1)
		stack->head = NULL;
	else
	{
		tail = stack->head->prev;
		tail->next = stack->head->next;

		stack->head = node_to_pop->next;
		stack->head->prev = tail;
	}
	stack->size -= 1;

	free(node_to_pop);
	node_to_pop = NULL;
	return(value);
}
