/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:07:42 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:07:49 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_stack *to, t_stack *from, char *to_print)
{
	int	popped_val;

	if (!from || !to || from->size == 0)
		return ;
	popped_val = stack_pop(from);
	stack_push(to, popped_val);
	ft_putstr_fd(to_print, 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b, "pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a, "pb\n");
}
