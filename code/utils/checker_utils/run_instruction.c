/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:56:33 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/27 02:58:36 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	run_instruction(t_stack *a, t_stack *b, char *instruction)
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
