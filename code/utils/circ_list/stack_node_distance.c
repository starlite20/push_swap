/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:55:58 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:48:21 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_node_distance(t_stack *stack, t_node *node)
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
	if (distance > stack->size / 2)
		return ((stack->size - distance) * -1);
	return (distance);
}
