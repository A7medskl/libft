/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:03:25 by asakli            #+#    #+#             */
/*   Updated: 2026/11/05 13:32:19 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	world_len(char const *s, size_t position, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[position + len] != '\0' && s[position + len] != c)
	{
		len++;
	}
	return (len);
}

static char	**free_all(char **res, size_t j)
{
	if (!res)
		return (NULL);
	while (j > 0)
	{
		j--;
		free(res[j]);
	}
	free(res);
	return (NULL);
}

static char	**fill_words(char **res, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!res || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = world_len(s, i, c);
			res[j] = ft_substr(s, i, len);
			if (!res[j])
				return (free_all(res, j));
			i += len;
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	return (fill_words(res, s, c));
}
