/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:07:28 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:30 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		forward;
	int		reverse;
	int		i;
	int		alloc_size;
	char	*trimmed;

	forward = 0;
	reverse = ft_strlen(s1) - 1;
	while (s1[forward] && ft_char_in_set(set, s1[forward]))
		forward++;
	while ((reverse > forward) && ft_char_in_set(set, s1[reverse]))
		reverse--;
	alloc_size = reverse - forward + 1;
	if (alloc_size < 0)
		alloc_size = 0;
	trimmed = (char *)malloc(sizeof(char) * (alloc_size + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (forward <= reverse)
		*(trimmed + i++) = *(s1 + forward++);
	*(trimmed + i) = '\0';
	return (trimmed);
}
