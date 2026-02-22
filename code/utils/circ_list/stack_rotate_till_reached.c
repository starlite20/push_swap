#include "../../push_swap.h"

void stack_rotate_till_reached(t_stack *stack, char stack_id, t_node *node_to_be_head)
{
	int node_distance = stack_node_distance(stack,node_to_be_head);

	while(stack->head != node_to_be_head)
	{
		if(node_distance <= (stack->size/2))
		{
			if(stack_id == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if(stack_id == 'a')
				rra(stack);
			else
				rrb(stack);
		}
		
	}
}