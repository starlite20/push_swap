#include "../push_swap.h"

void swap_top(t_stack *stack)
{
	int temp;
	
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
}

void sa(t_stack *stack_a)
{
	if(!stack_a || stack_a->size < 2)
		return ;

	swap_top(stack_a);
	ft_putstr_fd("sa\n",1);
}

void sb(t_stack *stack_b)
{
	if(!stack_b || stack_b->size < 2)
		return;

	swap_top(stack_b);
	ft_putstr_fd("sb\n",1);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
	{
		swap_top(stack_a);
	}
	if (stack_b && stack_b->size >= 2)
 		swap_top(stack_b);

	// if ((stack_a && stack_a->size >= 2) || (stack_b && stack_b->size >= 2))
    	ft_putstr_fd("ss\n", 1);
}
