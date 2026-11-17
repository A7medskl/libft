/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:29:17 by asakli            #+#    #+#             */
/*   Updated: 2026/11/05 13:03:01 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
	{
		i++;
	}
	len = ft_strlen(s1);
	while (len > i && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	res = ft_substr(s1, i, len - i);
	return (res);
}
/*
**
** #include <stdio.h>
**
** int	main(void)
** {
** 	char	*r;
**
** 	r = ft_strtrim("   42nice  ", " "); //ahmed
** 	printf("[%s]", r);
** 	free(r);
** 	r = ft_strtrim("--bonjour-toi--", "-"); //bonjour-toi
** 	printf("[%s]", r);
** 	free(r);
** 	r = ft_strtrim("xxxx", "x"); //
** 	printf("[%s]", r);
** 	free(r);
** 	return (0);
** }
*/
