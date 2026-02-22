/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:57:33 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:58:44 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*find_spot_in_a(t_stack *a, int value_to_push)
{
	t_node	*target_spot;
	t_node	*cur;
	int		nodes_traversed;

	if (!a || a->size == 0)
		return (NULL);
	target_spot = NULL;
	cur = a->head;
	nodes_traversed = 0;
	while (nodes_traversed < a->size)
	{
		if (cur->value > value_to_push)
		{
			if (!target_spot || (target_spot->value > cur->value))
				target_spot = cur;
		}
		cur = cur->next;
		nodes_traversed++;
	}
	if (!target_spot)
		target_spot = stack_find_min(a);
	return (target_spot);
}

t_node	*find_spot_in_b(t_stack *b, int value_to_push)
{
	t_node	*target_spot;
	t_node	*cur;
	int		nodes_traversed;

	if (!b || b->size == 0)
		return (NULL);
	target_spot = NULL;
	cur = b->head;
	nodes_traversed = 0;
	while (nodes_traversed < b->size)
	{
		if (cur->value < value_to_push)
		{
			if (!target_spot || (target_spot->value < cur->value))
				target_spot = cur;
		}
		cur = cur->next;
		nodes_traversed++;
	}
	if (!target_spot)
		target_spot = stack_find_max(b);
	return (target_spot);
}

void	rotate_and_move(t_stack *a, t_stack *b, t_node *node_to_push_from_a)
{
	t_node	*push_to_b_before_this;
	int		dir_node_a;
	int		dir_node_b;

	push_to_b_before_this = find_spot_in_b(b, node_to_push_from_a->value);
	dir_node_a = stack_node_is_forward(a, node_to_push_from_a);
	dir_node_b = stack_node_is_forward(b, push_to_b_before_this);
	if ((dir_node_a == 1) && (dir_node_b == 1))
	{
		while ((a->head != node_to_push_from_a)
			&& (b->head != push_to_b_before_this))
			rr(a, b);
	}
	else if ((dir_node_a == -1) && (dir_node_b == -1))
	{
		while ((a->head != node_to_push_from_a)
			&& (b->head != push_to_b_before_this))
			rrr(a, b);
	}
	stack_rotate_till_reached(a, 'a', node_to_push_from_a);
	stack_rotate_till_reached(b, 'b', push_to_b_before_this);
	pb(a, b);
}
