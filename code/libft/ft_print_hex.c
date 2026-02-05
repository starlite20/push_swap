/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:57:29 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexnum_len(long long num)
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
		num /= 16;
		len++;
	}
	return (len);
}

int	print_hexnum(unsigned int to_print, char hex_format, t_flags *flags)
{
	int	printed;

	printed = 0;
	printed = print_hexnum_flags(flags, hex_format, to_print);
	ft_put_hexnbr_len(((unsigned int)to_print), hex_format, &printed, flags);
	if (flags->left_align == 1)
	{
		if (flags->left_align == 1)
			flags->left_align = 2;
		printed += print_hexnum_flags(flags, hex_format, to_print);
	}
	return (printed);
}

static void	print_hexnum_flags_support(t_flags *flags, int *printed, int *len)
{
	char	printchar;

	if (flags->space != 0)
		*len += 1;
	if (flags->hashtag != 0)
		*len += 2;
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

int	print_hexnum_flags(t_flags *flags, char hex_format, unsigned int unum)
{
	int		printed;
	int		len;

	printed = 0;
	len = hexnum_len(unum);
	if (flags->space == 1)
	{
		printed += print_single_character(' ');
		flags->space = -1;
	}
	if (flags->width > 0)
	{
		print_hexnum_flags_support(flags, &printed, &len);
	}
	if ((flags->hashtag == 1) && (unum != 0))
	{
		printed += print_single_character('0');
		printed += print_single_character(hex_format);
		flags->hashtag = -1;
	}
	return (printed);
}

void	ft_put_hexnbr_len(unsigned int to_print, char hex_format, int *printed,
		t_flags *flags)
{
	if (to_print >= 16)
	{
		ft_put_hexnbr_len(to_print / 16, hex_format, printed, flags);
		ft_put_hexnbr_len(to_print % 16, hex_format, printed, flags);
	}
	else
	{
		if (to_print >= 10)
		{
			if (hex_format == 'x')
				*printed += print_single_character((to_print - 10) + 'a');
			else
				*printed += print_single_character((to_print - 10) + 'A');
		}
		else
			*printed += print_single_character(to_print + '0');
	}
}
