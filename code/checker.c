/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:13:16 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/27 02:58:41 by ssujaude         ###   ########.fr       */
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
		if (!stack_a || !stack_b)
			error_exit(stack_a, stack_b);
		if (validate_and_store(stack_a, argc, argv) != 1)
			error_exit(stack_a, stack_b);
		if (read_and_run(stack_a, stack_b) == 1)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		stack_clear(&stack_a);
		stack_clear(&stack_b);
	}
	return (0);
}