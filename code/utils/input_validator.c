/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:03:25 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/25 23:30:55 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	process_and_store_num(t_stack *numList, char *str)
{
	long long	num;
	int			error;

	num = ft_atoll(str, &error);
	if (error || num > INT_MAX || num < INT_MIN)
		return (0);
	if (!stack_find_node(numList, (int)num))
	{
		if (stack_push_back(numList, (int)num) == 0)
			return (0);
		return (1);
	}
	return (0);
}

void	free_splitted_str(char **splitted_str)
{
	char	**temp;

	temp = splitted_str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(splitted_str);
}

int	process_splitted_str(char **splitted_str, t_stack *numList)
{
	int	split_index;

	split_index = 0;
	while (splitted_str[split_index])
	{
		if (ft_is_just_number(splitted_str[split_index]))
		{
			if (process_and_store_num(numList, splitted_str[split_index]) != 1)
			{
				free_splitted_str(splitted_str);
				return (0);
			}
		}
		else
		{
			free_splitted_str(splitted_str);
			return (0);
		}
		split_index++;
	}
	return (1);
}

int	validate_and_store(t_stack *numList, int count, char **input)
{
	int		arg_index;
	char	**splitted_str;

	arg_index = 1;
	while ((arg_index < count))
	{
		splitted_str = ft_split(input[arg_index++], ' ');
		if (!splitted_str)
			return (0);
		if (splitted_str[0] == NULL)
		{
			free(splitted_str);
			return (0);
		}
		if (process_splitted_str(splitted_str, numList) == 0)
			return (0);
		free_splitted_str(splitted_str);
	}
	return (1);
}

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		stack_clear(&stack_a);
	if (stack_b)
		stack_clear(&stack_b);
	ft_puterr_exit();
}
