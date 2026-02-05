/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:52:37 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:01 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int replaceWith, size_t len)
{
	char	*strptr;

	strptr = pointer;
	while (len > 0)
	{
		*strptr = (unsigned char)replaceWith;
		strptr += sizeof(unsigned char);
		len--;
	}
	return (pointer);
}
