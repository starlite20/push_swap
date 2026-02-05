/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:56:40 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:11 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	character;

	character = (unsigned char)c;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == character)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == character)
		return ((char *)(s + i));
	return (NULL);
}
