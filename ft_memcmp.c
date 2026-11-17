/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:00:25 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:01:33 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	if (!buf1 || !buf2)
		return (0);
	i = 0;
	b1 = (unsigned char *)buf1;
	b2 = (unsigned char *)buf2;
	while (i < n)
	{
		if (b1[i] != b2[i])
		{
			return (b1[i] - b2[i]);
		}
		i++;
	}
	return (0);
}
/*
** 
** #include <stdio.h>
** #include <string.h>
** 
** int main(int argc, char ** argv)
** {
**   int  len;
**   int  result;
** 
**   if ( argc != 3 )
**   {
**      printf( "Usage: %s string1 string2\n", argv[0] );
**   }
**   else
**   {
**      if (strlen( argv[1] ) < strlen( argv[2] ))
**        len = strlen( argv[1] );
**      else
**        len = strlen( argv[2] );
** 
**      result = ft_memcmp( argv[1], argv[2], len );
** 
**      printf( "When the first %i characters are compared,\n", len );
**      if ( result == 0 )
**        printf( "\"%s\" is identical to \"%s\"\n", argv[1], argv[2] );
**      else if ( result < 0 )
**        printf( "\"%s\" is less than \"%s\"\n", argv[1], argv[2] );
**      else
**        printf( "\"%s\" is greater than \"%s\"\n", argv[1], argv[2] );
**    }
** }
*/