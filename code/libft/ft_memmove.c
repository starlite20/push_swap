/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:17:06 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:00 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				adder;
	size_t				i;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (!dest_ptr && !src_ptr)
		return (NULL);
	i = 0;
	adder = 1;
	if (dest_ptr > src_ptr)
	{
		adder *= -1;
		dest_ptr += (len - 1);
		src_ptr += (len - 1);
	}
	while (i < len)
	{
		*(dest_ptr) = *(src_ptr);
		dest_ptr += adder;
		src_ptr += adder;
		i++;
	}
	return (dest);
}
