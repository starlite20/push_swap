/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:26:34 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:27 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)(haystack));
	i = 0;
	while (*(haystack + i) && (i < len))
	{
		j = 0;
		while ((*(haystack + (i + j)) != '\0')
			&& (*(haystack + (i + j)) == *(needle + j)) && (i + j < len))
		{
			if (*(needle + j + 1) == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
