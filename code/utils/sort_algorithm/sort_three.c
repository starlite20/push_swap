/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:17:55 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 00:21:25 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stack *numStack)
{
	int	first;
	int	second;
	int	third;

	first = numStack->head->value;
	second = numStack->head->next->value;
	third = numStack->head->next->next->value;
	if ((first < second) && (second > third) && (first < third))
	{
		sa(numStack);
		ra(numStack);
	}
	else if ((first > second) && (second < third) && (first < third))
		sa(numStack);
	else if ((first < second) && (second > third) && (first > third))
		rra(numStack);
	else if ((first > second) && (second < third) && (first > third))
		ra(numStack);
	else if ((first > second) && (second > third) && (first > third))
	{
		ra(numStack);
		sa(numStack);
	}
}
