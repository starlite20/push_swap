/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_is_forward.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:55:51 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/22 23:55:52 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_node_is_forward(t_stack *stack, t_node *node)
{
	t_node	*cur;
	int		distance;

	cur = stack->head;
	distance = 0;
	while (cur != node)
	{
		cur = cur->next;
		distance += 1;
	}
	if (distance == 0)
		return (0);
	else if (distance > stack->size / 2)
		return (-1);
	return (1);
}
