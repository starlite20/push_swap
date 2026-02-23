/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:56:28 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/24 00:33:54 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_clear(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	while ((*stack)->size > 0)
	{
		stack_pop(*stack);
	}
	free(*stack);
	*stack = NULL;
}
