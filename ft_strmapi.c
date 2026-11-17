/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:47:02 by asakli            #+#    #+#             */
/*   Updated: 2026/11/05 15:47:02 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
** #include <stdio.h>
**
** char myfunction(unsigned int index, char c)
** {
** 	return c + index; // Increment each character by its index
** };
** int main(void)
** {
**
** 	char *result = ft_strmapi("Hello", myfunction);
** 	// 	return c + i; // Hello -->
**
** 	if (result)
** 	{
** 		printf("Result: %s\n", result); // Should print "Hfnos"
** 		free(result);
** 	}
** 	else
** 	{
** 		printf("Memory allocation failed.\n");
** 	}
**
** 	return 0;
** }
*/