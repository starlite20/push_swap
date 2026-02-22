/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:08:14 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:08:36 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_top(t_stack *stack, char *to_print)
{
	int	temp;

	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	ft_putstr_fd(to_print, 1);
}

void	sa(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	swap_top(stack_a, "sa\n");
}

void	sb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	swap_top(stack_b, "sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
	{
		swap_top(stack_a, "");
	}
	if (stack_b && stack_b->size >= 2)
		swap_top(stack_b, "");
	ft_putstr_fd("ss\n", 1);
}
