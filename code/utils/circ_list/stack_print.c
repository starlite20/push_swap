#include "../../push_swap.h"

void stack_print(t_stack *stack)
{
	t_node *head;
	int nodes_iterated;

	nodes_iterated = 0;
	head = stack->head;
	
	ft_printf("\n");
	while(nodes_iterated < stack->size)
	{
		ft_printf("\t%d", head->value);
		head = head->next;
		nodes_iterated++;
	}
	ft_printf("\n");
}
