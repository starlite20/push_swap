/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:55:45 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 01:08:12 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_pop(t_stack *stack)
{
	int		value;
	t_node	*node_to_pop;
	t_node	*tail;

	node_to_pop = stack->head;
	if (!node_to_pop)
	{
		ft_puterr_exit();
	}
	value = node_to_pop->value;
	if (stack->size == 1)
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
	return (value);
}
