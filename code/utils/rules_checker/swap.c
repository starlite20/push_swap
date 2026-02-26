/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:08:14 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/26 18:12:33 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap_top_silent(t_stack *stack)
{
	int	temp;

	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
}

void	sa_silent(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	swap_top_silent(stack_a);
}

void	sb_silent(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	swap_top_silent(stack_b);
}

void	ss_silent(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
	{
		swap_top_silent(stack_a);
	}
	if (stack_b && stack_b->size >= 2)
		swap_top_silent(stack_b);
}
