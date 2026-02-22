/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:57:29 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 01:22:02 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	update_min_node(t_node **min_cost_node, int *min_cost, t_node *cur,
		int cost)
{
	if (*min_cost_node == NULL || (*min_cost > cost))
	{
		*min_cost = cost;
		*min_cost_node = cur;
	}
}

t_node	*find_cheapest_node(t_stack *a, t_stack *b, int nodes_traversed)
{
	t_node	*cur;
	t_node	*min_cost_node;
	int		min_cost;
	int		cost_a;
	int		cost_b;

	cur = a->head;
	min_cost_node = NULL;
	min_cost = INT_MAX;
	while (nodes_traversed++ < a->size)
	{
		cost_a = stack_node_distance(a, cur);
		cost_b = 0;
		if (b->size != 0)
			cost_b = stack_node_distance(b, find_spot_in_b(b, cur->value));
		if (((cost_a < 0) && (cost_b < 0)) || ((cost_a >= 0) && (cost_b >= 0)))
			update_min_node(&min_cost_node, &min_cost, cur,
				ft_max(ft_abs(cost_a), ft_abs(cost_b)));
		else
			update_min_node(&min_cost_node, &min_cost, cur, (ft_abs(cost_a)
					+ ft_abs(cost_b)));
		cur = cur->next;
	}
	return (min_cost_node);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_node	*node_to_push;

	pb(a, b);
	pb(a, b);
	while (a->size > 3)
	{
		node_to_push = find_cheapest_node(a, b, 0);
		if (node_to_push)
			rotate_and_move(a, b, node_to_push);
	}
	sort_three(a);
	while (b->size > 0)
	{
		stack_rotate_till_reached(a, 'a', find_spot_in_a(a, b->head->value));
		pa(a, b);
	}
	stack_rotate_till_reached(a, 'a', stack_find_min(a));
}
