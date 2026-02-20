#include "../../push_swap.h"

t_node *stack_find_node(t_stack *stack, int value)
{
	t_node *current;
	int nodes_iterated;

	nodes_iterated = 0;
	current = stack->head;
	if(!current)
		return NULL;

	while(nodes_iterated < stack->size)
	{
		if(current->value == value)
			return(current);
		current = current->next;
		nodes_iterated++;
	}
	return(NULL);
}
