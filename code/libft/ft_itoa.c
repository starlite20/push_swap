/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:37:37 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:56:41 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(long num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		len++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*copy_num(char *numstr, long num, int i)
{
	if (num < 0)
	{
		numstr[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		numstr[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (numstr);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num_len;

	num_len = num_length(n);
	str = malloc(sizeof(char) * (num_len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
		copy_num(str, n, num_len - 1);
	str[num_len] = '\0';
	return (str);
}
