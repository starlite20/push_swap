/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:30:08 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:28 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	character;
	char			*found;

	character = (unsigned char)c;
	found = NULL;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == character)
			found = (char *)(s + i);
		i++;
	}
	if (*(s + i) == character)
		found = (char *)(s + i);
	return (found);
}
