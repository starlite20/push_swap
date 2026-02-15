#include "../../push_swap.h"

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

	return(stack);
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

void stack_push_back(t_stack *stack, int value)
{
	t_node *tail;
	t_node *newnode = create_node(value);
	if(!newnode)
		return ;

	if(stack->head == NULL)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		stack->head = newnode;
	}
	else
	{
		//old tail
		tail = stack->head->prev;

		newnode->next = stack->head;
		newnode->prev = tail;

		tail->next = newnode;
		stack->head->prev = newnode;
	}
	stack->size += 1;
}

int stack_pop(t_stack *stack)
{
	int value;
	t_node *node_to_pop;
	t_node *tail;

	node_to_pop = stack->head;

	if(!node_to_pop)
	{
		ft_puterr_exit("Error: Attempting to Pop an Empty Stack");
	}

	value = node_to_pop->value;

	if(stack->size == 1)
		stack->head = NULL;
	else
	{
		tail = stack->head->prev;
		tail->next = stack->head->next;

		stack->head = node_to_pop->next;
		stack->head->prev = tail;
	}
	stack->size -= 1;

	free(node_to_pop);
	node_to_pop = NULL;
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

t_node *stack_find_node(t_stack *stack, int value)
{
	t_node *current;
	int nodes_iterated;

	nodes_iterated = 0;
	current = stack->head;
	if(!current)
		return NULL;

	while(nodes_iterated < stack->size)
	{
		if(current->value == value)
			return(current);
		current = current->next;
		nodes_iterated++;
	}
	return(NULL);
}

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
