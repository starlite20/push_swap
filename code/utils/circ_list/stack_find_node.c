/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:56:07 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/22 23:56:08 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*stack_find_node(t_stack *stack, int value)
{
	t_node	*current;
	int		nodes_iterated;

	nodes_iterated = 0;
	current = stack->head;
	if (!current)
		return (NULL);
	while (nodes_iterated < stack->size)
	{
		if (current->value == value)
			return (current);
		current = current->next;
		nodes_iterated++;
	}
	return (NULL);
}
