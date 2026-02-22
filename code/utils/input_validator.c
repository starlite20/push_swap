/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:03:25 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/23 01:06:22 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	process_and_store_num(t_stack *numList, char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		ft_puterr_exit();
	else if (!stack_find_node(numList, num))
		stack_push_back(numList, num);
	else
		ft_puterr_exit();
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

void	validate_and_store(t_stack *numList, int count, char **input)
{
	int		arg_index;
	char	**splitted_str;
	int		split_index;

	arg_index = 1;
	while ((arg_index < count))
	{
		splitted_str = ft_split(input[arg_index], ' ');
		if (!splitted_str)
			ft_puterr_exit();
		split_index = 0;
		while (splitted_str[split_index])
		{
			if (ft_is_just_number(splitted_str[split_index]))
				process_and_store_num(numList, splitted_str[split_index]);
			else
			{
				free_splitted_str(splitted_str);
				ft_puterr_exit();
			}
			split_index++;
		}
		free_splitted_str(splitted_str);
		arg_index++;
	}
}
