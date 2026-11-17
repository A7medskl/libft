/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:49:06 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:49:36 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(str + i));
	return (NULL);
}
/*
** #define SIZE 40
** 
** int main(void)
** {
**   char buffer1[SIZE] = "computer program";
**   char * ptr;
**   int    ch = 'p';
** 
**   ptr = ft_strchr( buffer1, ch );
**   printf( "The first occurrence of %c in '%s' is '%s'\n",
**             ch, buffer1, ptr );
** 
** }
*/