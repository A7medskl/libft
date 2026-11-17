/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:31:53 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:49:08 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	if (!dst || !src)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && dlen + i + 1 < size)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
/*
** 
** #include <stdio.h>
** #include <string.h>
** int main(void)
** {
**     char dest[7] = "bonjour";
**     char src[] = "123";
** 
**     size_t t = ft_strlcat(dest, src, sizeof dest);
**     printf("\n%s\n", dest);
** 	printf("l : %zu\n",t);
** 
**     return 0;
** }
*/