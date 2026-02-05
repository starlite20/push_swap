/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:01:04 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
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

int	print_number(int to_print, t_flags *flags)
{
	int	printed;

	printed = 0;
	printed += print_num_flags(flags, to_print);
	printed += ft_put_nbr_len(to_print, flags);
	if (flags->left_align == 1)
	{
		if (flags->left_align == 1)
			flags->left_align = 2;
		printed += print_num_flags(flags, to_print);
	}
	return (printed);
}
