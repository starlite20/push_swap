/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:15:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_format_specifier(char character)
{
	if ((character == 'c') || (character == 's') || (character == 'p')
		|| (character == 'd') || (character == 'i') || (character == 'u')
		|| (character == 'x') || (character == 'X') || (character == '%'))
		return (1);
	return (-1);
}

static void	print_argument_support(char fs_val, t_flags *flags, int *printed,
		va_list args)
{
	if (fs_val)
	{
		if (is_format_specifier(fs_val) == 1)
		{
			if (fs_val == 'c')
				*printed += print_character(va_arg(args, int), flags);
			else if (fs_val == 's')
				*printed += print_string(va_arg(args, char *), flags);
			else if ((fs_val == 'd') || (fs_val == 'i'))
				*printed += print_number(va_arg(args, int), flags);
			else if (fs_val == 'u')
				*printed += print_unsigned_number(va_arg(args, int), flags);
			else if (fs_val == 'p')
				*printed += print_address(va_arg(args, void *), flags);
			else if ((fs_val == 'x') || (fs_val == 'X'))
				*printed += print_hexnum(va_arg(args, unsigned int), fs_val,
						flags);
			else if (fs_val == '%')
				*printed += print_percentage();
		}
		else
			*printed += print_single_character(fs_val);
	}
}

static void	identify_flags(char *str, t_flags *flags, int *i)
{
	while (*(str + *i))
	{
		if (process_flag(*(str + *i), flags) == 1)
			*i = *i + 1;
		else if (ft_isdigit(*(str + *i)))
			*i += process_numflag(str + *i, flags);
		else
			break ;
	}
}

int	print_argument(char *str, int *printed, va_list args)
{
	int		skip_val;
	char	fs_val;
	int		i;
	t_flags	*flags;

	flags = ft_calloc(1, sizeof(t_flags));
	i = 1;
	skip_val = 1;
	fs_val = *(str + 1);
	initiate_flags(flags);
	identify_flags(str, flags, &i);
	if (is_format_specifier(*(str + i)))
		fs_val = *(str + i);
	print_argument_support(fs_val, flags, printed, args);
	if (fs_val)
		skip_val += i;
	free(flags);
	return (skip_val);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		skip;
	int		printed;
	va_list	args;

	va_start(args, str);
	i = 0;
	skip = 0;
	printed = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			skip = print_argument((char *)(str + i), &printed, args);
			i += skip;
		}
		else
		{
			printed += write(1, (str + i), 1);
			i++;
		}
	}
	va_end(args);
	return (printed);
}
