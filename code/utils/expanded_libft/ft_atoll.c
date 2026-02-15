/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:04:41 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/15 23:54:43 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r')
		|| (c == ' '))
		return (1);
	return (0);
}

static int	checksign(int c, unsigned long *i)
{
	if (c == '-' || c == '+')
	{
		(*i)++;
		if (c == '-')
			return (-1);
	}
	return (1);
}



long long ft_atoll(const char *str)
{
    long long num = 0;
    int sign = 1;
    int i = 0;

    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if ((num > LLONG_MAX / 10) || ((num == LLONG_MAX / 10)
				&& (str[i] - '0') > LLONG_MAX % 10))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
}