/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:56:33 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/27 02:58:24 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	read_and_run(t_stack *a, t_stack *b)
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
