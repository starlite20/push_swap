#include "../../push_swap.h"

void reverse_rotate(t_stack *stack, char *to_print)
{
	if(!stack || stack->size < 2)
		return;

	stack->head = stack->head->prev;

	ft_putstr_fd(to_print, 1);
}

void rra(t_stack *stack_a)
{
	reverse_rotate(stack_a, "rra\n");
}

void rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b, "rrb\n");
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "");
	reverse_rotate(stack_b, "");
	ft_putstr_fd("rrr\n",1);
}