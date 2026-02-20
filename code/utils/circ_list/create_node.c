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
