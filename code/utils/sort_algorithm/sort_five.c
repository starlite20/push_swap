/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:17:53 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:21:39 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3)
	{
		min = stack_find_min(a);
		stack_rotate_till_reached(a, 'a', min);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
	{
		pa(a, b);
	}
}
