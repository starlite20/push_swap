/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:07:57 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/26 18:12:56 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_stack *stack, char *to_print)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	ft_putstr_fd(to_print, 1);
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a, "rra\n");
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b, "rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, "");
	reverse_rotate(stack_b, "");
	ft_putstr_fd("rrr\n", 1);
}
