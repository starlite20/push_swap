/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:01:01 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/24 00:39:55 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = stack_init();
		stack_b = stack_init();
		if(validate_and_store(stack_a, argc, argv) != 1)
			error_exit(stack_a, stack_b);
		sort_stack(stack_a, stack_b);

		stack_clear(&stack_a);
		stack_clear(&stack_b);
	}
	return (0);
}
