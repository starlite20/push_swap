/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:56:12 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/22 23:58:33 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*stack_find_min(t_stack *stack)
{
	t_node	*cur;
	t_node	*min;

	min = stack->head;
	cur = stack->head->next;
	while (cur != stack->head)
	{
		if (cur->value < min->value)
			min = cur;
		cur = cur->next;
	}
	return (min);
}
