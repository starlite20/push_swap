/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:03:25 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/24 00:40:16 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	process_and_store_num(t_stack *numList, char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else if (!stack_find_node(numList, num))
	{
		stack_push_back(numList, num);
		return(1);
	}
	else
		return(0);
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

int	validate_and_store(t_stack *numList, int count, char **input)
{
	int		arg_index;
	char	**splitted_str;
	int		split_index;

	arg_index = 1;
	while ((arg_index < count))
	{
		splitted_str = ft_split(input[arg_index], ' ');
		if (!splitted_str)
		{
			stack_clear(&numList);
			ft_puterr_exit();
		}
		split_index = 0;
		while (splitted_str[split_index])
		{
			if (ft_is_just_number(splitted_str[split_index]))
			{
				if(process_and_store_num(numList, splitted_str[split_index]) != 1)
				{
					free_splitted_str(splitted_str);
					return(0);
				}
			}	
			else
			{
				free_splitted_str(splitted_str);
				return(0);
			}
			split_index++;
		}
		free_splitted_str(splitted_str);
		arg_index++;
	}
	return(1);
}

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
        stack_clear(&stack_a);
    if (stack_b)
        stack_clear(&stack_b);
    ft_puterr_exit();
}
