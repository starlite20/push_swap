/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_mgr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 01:22:13 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_format_flag(char character)
{
	if ((character == '+') || (character == '#') || (character == '-')
		|| (character == ' ') || (character == '0') || (character == '.'))
		return (1);
	return (-1);
}

void	initiate_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->left_align = 0;
	flags->hashtag = 0;
	flags->dot = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
}

static void	update_flags(char character, t_flags *flags)
{
	if (character == '-')
	{
		flags->left_align = 1;
		flags->zero = 0;
	}
	else if (character == '#')
		flags->hashtag = 1;
	else if (character == ' ')
	{
		if (flags->plus == 0)
			flags->space = 1;
	}
}

int	process_flag(char character, t_flags *flags)
{
	if (is_format_flag(character) != -1)
	{
		if (character == '+')
		{
			flags->plus = 1;
			flags->space = 0;
		}
		else if (character == '.')
		{
			flags->dot = 1;
			flags->zero = 0;
		}
		else if (character == '0')
		{
			if (flags->left_align != 1)
				flags->zero = 1;
		}
		else
			update_flags(character, flags);
		return (1);
	}
	return (0);
}

int	process_numflag(char *str, t_flags *flags)
{
	int	value;

	value = ft_atoi(str);
	if (flags->dot == 1)
		flags->precision = value;
	else
		flags->width = value;
	return (num_len(value));
}
