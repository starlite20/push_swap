/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:39:41 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_string_len(char *to_print, int len)
{
	return (write(1, to_print, len));
}

int	print_string(char *to_print, t_flags *flags)
{
	int	printed;
	int	len;

	printed = 0;
	if (to_print == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen(to_print);
	printed += print_string_based_on_flag(flags, to_print, len);
	printed += write(1, to_print, len);
	if (flags->left_align == 1)
		flags->left_align = 2;
	printed += print_string_based_on_flag(flags, to_print, len);
	return (printed);
}

int	print_string_based_on_flag(t_flags *flags, char *to_print, int len)
{
	int	printed;

	printed = 0;
	ft_strlen(to_print);
	if (flags->width > 0)
	{
		if ((flags->left_align == 0) || (flags->left_align == 2))
		{
			while (printed < (flags->width - len))
				printed += print_single_character(' ');
			flags->width = -1;
		}
		if (flags->left_align == 2)
			flags->left_align = -1;
	}
	return (printed);
}
