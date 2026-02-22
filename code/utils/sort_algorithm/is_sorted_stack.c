/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:17:58 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:18:20 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_sorted_stack(t_stack *numList)
{
	t_node	*cur;
	int		sorted;

	cur = numList->head->next;
	sorted = 1;
	while (cur != numList->head)
	{
		if (cur->value < cur->prev->value)
		{
			sorted = 0;
			break ;
		}
		cur = cur->next;
	}
	return (sorted);
}
