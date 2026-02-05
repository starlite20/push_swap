/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:17:46 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:56:17 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer, size_t len)
{
	unsigned char	*strptr;
	size_t			i;

	i = 0;
	strptr = (unsigned char *)pointer;
	while (i < len)
	{
		*(strptr + i) = 0;
		i++;
	}
	return ;
}
