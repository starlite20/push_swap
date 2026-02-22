/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:08:06 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:08:54 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_stack *stack, char *to_print)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	ft_putstr_fd(to_print, 1);
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a, "ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b, "rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, "");
	rotate(stack_b, "");
	ft_putstr_fd("rr\n", 1);
}
