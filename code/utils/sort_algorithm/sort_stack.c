/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:19:48 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:21:54 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (is_sorted_stack(a) == 0)
	{
		if (a->size == 2)
			sa(a);
		else if (a->size == 3)
			sort_three(a);
		else if (a->size <= 5)
			sort_five(a, b);
		else
			turk_sort(a, b);
	}
}
