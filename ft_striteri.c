/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:58:54 by asakli            #+#    #+#             */
/*   Updated: 2026/11/05 15:58:54 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
** #include <stdio.h>
**
** void	myfunction(unsigned int index, char *c)
** {
** 	*c = *c + index;
** }
**
** int	main(void)
** {
** 	char	result[] = "Hello";
**
** 	ft_striteri(result, myfunction);
** 	printf("Result: %s\n", result);
** 	return (0);
** }
*/