/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:56:52 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned_number(unsigned int to_print, t_flags *flags)
{
	int	printed;

	flags->plus = 0;
	printed = 0;
	printed += print_unum_flags(flags, to_print);
	printed += ft_put_unbr_len(to_print, flags);
	if (flags->left_align == 1)
	{
		if (flags->left_align == 1)
			flags->left_align = 2;
		printed += print_num_flags(flags, to_print);
	}
	return (printed);
}

static void	print_unum_flags_support(t_flags *flags, int *printed, int *len)
{
	char	printchar;

	if (flags->width > 0)
	{
		if (flags->space != 0)
			*len += 1;
		if ((flags->left_align == 0) || (flags->left_align == 2))
		{
			if (flags->zero != 1)
				printchar = ' ';
			else
				printchar = '0';
			if (flags->width > *len)
			{
				while (*printed < (flags->width - *len))
					*printed += print_single_character(printchar);
			}
			flags->width = -1;
			if (flags->left_align == 2)
				flags->left_align = -1;
		}
	}
}

int	print_unum_flags(t_flags *flags, unsigned int unum)
{
	int		printed;
	int		len;

	printed = 0;
	len = num_len(unum);
	if (flags->space == 1)
	{
		printed += print_single_character(' ');
		flags->space = -1;
	}
	print_unum_flags_support(flags, &printed, &len);
	return (printed);
}

int	ft_put_unbr_len(unsigned int unum, t_flags *flags)
{
	int	printed;

	printed = 0;
	if (unum >= 10)
		printed += ft_put_unbr_len(unum / 10, flags);
	ft_putchar_fd(('0' + (unum % 10)), 1);
	printed++;
	return (printed);
}
