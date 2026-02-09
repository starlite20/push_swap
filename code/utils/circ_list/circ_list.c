#include "../push_swap.h"

t_node *create_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node) * 1);
	if(!node)
		return (NULL);
	
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack *stack_init()
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack) * 1);
	if(!stack)
		return(NULL);
	
	stack->head = NULL;
	stack->size = 0;

	return(t_stack);
}



void stack_push(t_stack *stack, int value)
{
	t_node *tail;
	t_node *newnode = create_node(value);
	if(!newnode)
		return ;

	if(stack->head == NULL)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
	}
	else
	{
		tail = stack->head->prev;

		newnode->next = stack->head;
		newnode->prev = tail;

		tail->next = newnode;
		stack->head->prev = newnode;
	}
	stack->head = newnode;
	stack->size += 1;
}

int stack_pop(t_stack *stack)
{
	int value;
	t_node *node_to_pop;

	node_to_pop = stack->head;
	value = node_to_pop->value;

	node_to_pop->prev->next = node_to_pop->next;
	free(node_to_pop);
	return(value);
}

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

int stack_size(t_stack *stack)
{
	// i wont be needing this right? as i have the size updated on the structure always...?	
}