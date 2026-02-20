#include "../../push_swap.h"

void stack_clear(t_stack **stack)
{
	if(!*stack || !(*stack)->head)
		return ;

	while((*stack)->size > 0)
	{
		stack_pop(*stack);
	}
	free(*stack);
	*stack = NULL;
}
