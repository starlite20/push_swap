#include "../../push_swap.h"

void push(t_stack *to, t_stack *from, char *to_print)
{
	int popped_val;

	if(!from || !to || from->size == 0)
		return;

	popped_val = stack_pop(from);
	stack_push(to, popped_val);

	ft_putstr_fd(to_print,1);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b, "pa\n");
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a, "pb\n");
}
