/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:55:36 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 13:12:06 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/*
** #include <stdio.h>
** int main(void)
** {
** 	size_t result1 = ft_strlen('A'); // Should return 1
** 	size_t result2 = ft_strlen('Abc'); // Should return 3
** 	size_t result3 = ft_strlen('A  b'); // Should return 4
** 
** 	printf("ft_strlen('A'): %d\n", result1);
** 	printf("ft_strlen('Abc'): %d\n", result1);
** 	printf("ft_strlen('A  b'): %d\n", result1);
** 	return 0;
** }
*/