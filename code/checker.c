/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:13:16 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/27 02:14:48 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_instruction(t_stack *a, t_stack *b, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa_silent(a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb_silent(b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss_silent(a, b);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa_silent(a, b);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb_silent(a, b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra_silent(a);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb_silent(b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr_silent(a, b);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra_silent(a);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb_silent(b);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr_silent(a, b);
	else
		return (0);
	return (1);
}

static int	read_and_run(t_stack *a, t_stack *b)
{
	char	*instruction;

	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		if (run_instruction(a, b, instruction) == 0)
		{
			free(instruction);
			instruction = NULL;
			error_exit(a, b);
		}
		free(instruction);
		instruction = NULL;
	}
	return (is_sorted_stack(a) && b->size == 0);
}

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