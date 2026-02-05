/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:43:12 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:13 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexaddr_len(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	print_address(void *to_print, t_flags *flags)
{
	int	printed;

	printed = 0;
	printed += print_hexaddr_flags(flags, (unsigned long long)to_print);
	if (to_print == NULL)
		printed += ft_put_string_len("0x0", 3);
	else
	{
		printed += ft_put_string_len("0x", 2);
		ft_put_hexaddress(((unsigned long long)to_print), &printed, flags);
	}
	if (flags->left_align == 1)
	{
		if (flags->left_align == 1)
			flags->left_align = 2;
		printed += print_hexaddr_flags(flags, (unsigned long long)to_print);
	}
	return (printed);
}

int	print_hexaddr_flags(t_flags *flags, unsigned long long addr)
{
	int		printed;
	int		len;
	char	printchar;

	printed = 0;
	len = hexaddr_len(addr) + 2;
	if (flags->width > 0)
	{
		if ((flags->left_align == 0) || (flags->left_align == 2))
		{
			if (flags->zero != 1)
				printchar = ' ';
			else
				printchar = '0';
			if (flags->width > len)
			{
				while (printed < (flags->width - len))
					printed += print_single_character(printchar);
			}
			flags->width = -1;
			if (flags->left_align == 2)
				flags->left_align = -1;
		}
	}
	return (printed);
}

void	ft_put_hexaddress(unsigned long long to_print, int *printed,
		t_flags *flags)
{
	if (to_print >= 16)
	{
		ft_put_hexaddress(to_print / 16, printed, flags);
		ft_put_hexaddress(to_print % 16, printed, flags);
	}
	else
	{
		if (to_print >= 10)
			*printed += print_single_character((to_print - 10) + 'a');
		else
			*printed += print_single_character(to_print + '0');
	}
}
