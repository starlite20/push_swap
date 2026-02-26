/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:07:57 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/26 18:12:17 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate_silent(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
}

void	rra_silent(t_stack *stack_a)
{
	reverse_rotate_silent(stack_a);
}

void	rrb_silent(t_stack *stack_b)
{
	reverse_rotate_silent(stack_b);
}

void	rrr_silent(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_silent(stack_a);
	reverse_rotate_silent(stack_b);
}
