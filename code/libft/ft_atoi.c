/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:04:41 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 23:15:50 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r')
		|| (c == ' '))
		return (1);
	return (0);
}

int	checksign(int c, unsigned long *i)
{
	if (c == '-' || c == '+')
	{
		(*i)++;
		if (c == '-')
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long	i;
	unsigned long	num;
	int				sign;

	num = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = checksign(str[i], &i);
	while (ft_isdigit(str[i]))
	{
		if ((num > LLONG_MAX / 10) || ((num == LLONG_MAX / 10)
				&& (str[i] - '0') > LLONG_MAX % 10))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	num *= sign;
	return (num);
}
