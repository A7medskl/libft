/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:08:28 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 13:11:45 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest || !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
		return (ft_memcpy(dest, src, n));
	i = n;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (dest);
}
/*
** 
** #include <stdio.h>
** #include <string.h>
** 
** #define ELEMENT_COUNT 10
** 
** int main() {
** 
**     // que neuf valeurs. La dixième est non utilisée (0).
**     int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };
** 
**     for( int i=0; i<ELEMENT_COUNT; i++ ) {
**         printf( "%d ", data[i] );
**     }
**     puts( "" );  // Un retour à la ligne
**     void * source = (void *) data;
**     void * destination = (void *) ( data + 1 );
**     size_t size = ELEMENT_COUNT * sizeof( int );
**     ft_memmove( destination, source, size );
** 
**     data[0] = 10;
** 
**     for( int i=0; i<ELEMENT_COUNT; i++ ) {
**         printf( "%d ", data[i] );
**     }
**     puts( "" );  // Un retour à la ligne
** 
**     return EXIT_SUCCESS;
** }
*/