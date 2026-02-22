/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_till_reached.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:55:18 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 01:10:32 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_rotate_till_reached(t_stack *stack, char stack_id,
		t_node *node_to_be_head)
{
	if (!stack || stack->size == 0 || !node_to_be_head)
		return ;
	while (stack->head != node_to_be_head)
	{
		if (stack_node_is_forward(stack, node_to_be_head) == 1)
		{
			if (stack_id == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_id == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}
