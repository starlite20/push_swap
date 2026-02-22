/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:56:17 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/22 23:58:18 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*stack_find_max(t_stack *stack)
{
	t_node	*cur;
	t_node	*max;

	max = stack->head;
	cur = stack->head->next;
	while (cur != stack->head)
	{
		if (cur->value > max->value)
			max = cur;
		cur = cur->next;
	}
	return (max);
}
