/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:08:06 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/26 18:12:29 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate_silent(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	ra_silent(t_stack *stack_a)
{
	rotate_silent(stack_a);
}

void	rb_silent(t_stack *stack_b)
{
	rotate_silent(stack_b);
}

void	rr_silent(t_stack *stack_a, t_stack *stack_b)
{
	rotate_silent(stack_a);
	rotate_silent(stack_b);
}
