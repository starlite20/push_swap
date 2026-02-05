/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:41:13 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:56:19 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	actual_size;

	if ((size > 0 && (nmemb > (SIZE_MAX / size))))
		return (NULL);
	actual_size = nmemb * size;
	ptr = malloc(actual_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, actual_size);
	return (ptr);
}
