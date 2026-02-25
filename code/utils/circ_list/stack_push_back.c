/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:55:34 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/24 01:00:47 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_push_back(t_stack *stack, int value)
{
	t_node	*tail;
	t_node	*newnode;

	newnode = create_node(value);
	if (!newnode)
		return (0);
	if (stack->head == NULL)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		stack->head = newnode;
	}
	else
	{
		tail = stack->head->prev;
		newnode->next = stack->head;
		newnode->prev = tail;
		tail->next = newnode;
		stack->head->prev = newnode;
	}
	stack->size += 1;
	return (1);
}
