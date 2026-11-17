/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:09:08 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:48:57 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (!dst || !src)
		return (0);
	len = 0;
	while (len + 1 < size && src[len] != '\0')
	{
		dst[len] = src[len];
		len++;
	}
	if (size > 0)
		dst[len] = '\0';
	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}
/*
** #include <stdio.h>
** #include <string.h>
** int main(void)
** {
** 	char b[7];
** 	char *t = "bonjour tout le monde";
** 
** 	size_t l = ft_strlcpy(b,t , sizeof b);
** 	printf("contenur : %s\n",b);
** 	printf("l : %zu\n",l);
** 	return 0;
** }
*/