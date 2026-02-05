/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:55:59 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num_flags_support_print(t_flags *flags, int *printed,
		int *len, char printchar)
{
	if (flags->width > *len)
	{
		while (*printed < (flags->width - *len))
			*printed += print_single_character(printchar);
		flags->width = -1;
	}
	if (flags->precision > *len)
	{
		while (*printed < (flags->precision - *len))
			*printed += print_single_character(printchar);
		flags->precision = -1;
	}
	if (flags->left_align == 2)
		flags->left_align = -1;
}

static void	print_num_flags_support_one(t_flags *flags, int *printed, int *len)
{
	char	printchar;

	if ((flags->width > 0) || (flags->precision > 0))
	{
		if ((flags->left_align == 0) || (flags->left_align == 2))
		{
			if (((flags->zero == 1) && (flags->dot == 0)) || ((flags->zero == 0)
					&& (flags->dot == 1)))
				printchar = '0';
			else
				printchar = ' ';
			print_num_flags_support_print(flags, printed, len, printchar);
		}
	}
}

static void	print_num_flags_support_two(int num, t_flags *flags, int *printed)
{
	if (((flags->plus == 1) && (flags->left_align == 0)) || ((flags->plus == 2)
			&& (flags->left_align == 1)))
	{
		if (num >= 0)
			*printed += print_single_character('+');
		flags->plus = -1;
	}
	if ((flags->plus == 1) && (flags->left_align == 1))
	{
		if (num >= 0)
			*printed += print_single_character('+');
		flags->plus = -1;
	}
}

int	print_num_flags(t_flags *flags, long long num)
{
	int	printed;
	int	len;

	printed = 0;
	len = num_len(num);
	if (num >= 0)
	{
		if ((flags->plus == 1) || (flags->plus == -1))
			len += 1;
	}
	if (flags->space == 1)
	{
		if (num >= 0)
			printed += print_single_character(' ');
		flags->space = -1;
	}
	if ((num < 0) && (flags->zero == 1))
		print_single_character('-');
	print_num_flags_support_one(flags, &printed, &len);
	print_num_flags_support_two(num, flags, &printed);
	return (printed);
}

int	ft_put_nbr_len(long long num, t_flags *flags)
{
	int	printed;

	printed = 0;
	if (num < 0)
	{
		if (flags->zero == 0)
			printed += print_single_character('-');
		else
			printed += 1;
		num *= -1;
	}
	if (num >= 10)
		printed += ft_put_nbr_len(num / 10, flags);
	if (!((flags->dot == 1) && (flags->precision == 0) && (num == 0)))
	{
		ft_putchar_fd(('0' + (num % 10)), 1);
		printed++;
	}
	return (printed);
}
