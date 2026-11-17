/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:53:17 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 13:53:55 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	res = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			res = (char *)(str + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (res);
}

/*
** #include <stdio.h>
** #include <string.h>
** 
** #define SIZE 40
** 
** int main(void)
** {
**   char buf[SIZE] = "computer program";
**   char * ptr;
**   int    ch = 'p';
** 
**   ptr = ft_strrchr( buf, ch );
**   printf( "The last occurrence of %c in '%s' is '%s'\n", ch, buf, ptr );
** }
*/