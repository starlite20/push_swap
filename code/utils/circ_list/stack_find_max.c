#include "../../push_swap.h"

t_node *stack_find_max(t_stack *stack)
{
	t_node *cur;
	t_node *max;

	max = stack->head;
	cur = stack->head->next;
	while(cur != stack->head)
	{
		if(cur->value > max->value)
			max = cur;
		cur = cur->next;
	}

	return max;
}