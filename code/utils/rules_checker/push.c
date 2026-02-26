/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:07:42 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/26 18:12:25 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_silent(t_stack *to, t_stack *from)
{
	int	popped_val;

	if (!from || !to || from->size == 0)
		return ;
	popped_val = stack_pop(from);
	stack_push(to, popped_val);
}

void	pa_silent(t_stack *stack_a, t_stack *stack_b)
{
	push_silent(stack_a, stack_b);
}

void	pb_silent(t_stack *stack_a, t_stack *stack_b)
{
	push_silent(stack_b, stack_a);
}
