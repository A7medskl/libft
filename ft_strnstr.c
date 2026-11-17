/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:02:13 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:04:09 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned char	*b;
	unsigned char	*l;
	size_t			i;
	size_t			j;

	if (!big || !little)
		return (NULL);
	i = 0;
	b = (unsigned char *)big;
	l = (unsigned char *)little;
	if (l[i] == '\0')
		return ((char *)big);
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		while (b[i + j] != '\0' && i + j < len && b[i + j] == l[j])
			j++;
		if (l[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
** #include <string.h>
** #include<stdio.h>
** 
** int	main()
** {
** 	char *largestring = "Foo Bar Baz";
**     char *smallstring = "Bar";
** 	char *ptr;
** 	ptr = ft_strnstr(largestring, smallstring, 4);
** 	printf("%s",ptr);
** }
*/