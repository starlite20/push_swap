/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:39:11 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/14 22:57:10 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_word_count(char const *s, char delimiter)
{
	int	wc;
	int	i;
	int	in_word;

	wc = 0;
	i = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if ((in_word == 0) && (s[i] != delimiter))
		{
			wc++;
			in_word = 1;
		}
		else if (s[i] == delimiter)
			in_word = 0;
		i++;
	}
	return (wc);
}

static char	*copy_word(const char *src, int start, int len)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(dest + i) = *(src + start + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

static char	**free_ptrs(char **splitted)
{
	int	i;

	if (!splitted)
		return (NULL);
	i = 0;
	while (*(splitted + i))
	{
		free(*(splitted + i));
		i++;
	}
	free(splitted);
	return (NULL);
}

static char	**split_process(char **split, const char *s, char c, int wrdct)
{
	int	start_in;
	int	s_i;
	int	wsc;

	start_in = -1;
	s_i = 0;
	wsc = 0;
	while (wsc < wrdct)
	{
		while (s[s_i] == c)
			s_i++;
		start_in = s_i;
		while ((s[s_i] != c) && s[s_i])
			s_i++;
		if (start_in < s_i)
		{
			*(split + wsc) = copy_word(s, start_in, (s_i - start_in));
			if (!(*(split + wsc)))
				return (free_ptrs(split));
			wsc++;
		}
	}
	*(split + wsc) = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		wrdct;

	if (!s)
		return (NULL);
	wrdct = calc_word_count(s, c);
	split = malloc(sizeof(char *) * (wrdct + 1));
	if (!split)
		return (NULL);
	split = split_process(split, s, c, wrdct);
	return (split);
}
