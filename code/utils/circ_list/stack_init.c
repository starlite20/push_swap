#include "../../push_swap.h"

t_stack *stack_init()
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack) * 1);
	if(!stack)
		return(NULL);
	
	stack->head = NULL;
	stack->size = 0;

	return(stack);
}
