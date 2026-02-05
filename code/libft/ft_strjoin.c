/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:11:28 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:16 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*concatenated;
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	si;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concatenated = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!concatenated)
		return (NULL);
	i = 0;
	si = 0;
	while (si < (s1_len))
		*(concatenated + i++) = *(s1 + si++);
	si = 0;
	while (si < (s2_len))
		*(concatenated + i++) = *(s2 + si++);
	*(concatenated + i) = '\0';
	return (concatenated);
}
