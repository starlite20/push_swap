#include "../../push_swap.h"

int stack_node_is_forward(t_stack *stack, t_node *node)
{
	t_node *cur;
	int distance;

	cur = stack->head;
	distance = 0;
	while(cur != node)
	{
		cur = cur->next;
		distance += 1;
	}

	if(distance == 0)
		return (0);
	else if(distance > stack->size/2)
		return(-1);
	return (1);
}
