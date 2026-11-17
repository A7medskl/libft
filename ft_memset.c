/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:59:41 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 13:11:57 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*p;
	size_t			i;

	if (!pointer)
	{
		return (NULL);
	}
	i = 0;
	p = (unsigned char *)pointer;
	while (count > i)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (p);
}
/*
** #include <stdio.h>
** #include <string.h>
** 
** int main() {
** 
**     int array [] = { 54, 85, 20, 63, 21 };
**     size_t size = sizeof( int ) * 5;
**     int length;
**     for( length=0; length<5; length++) {
**         printf( "%d ", array[ length ] );
**     }
**     printf( "\n" );
** 
**     ft_memset( array, 0, size );
** 
**     for( length=0; length<5; length++) {
**         printf( "%d ", array[ length ] );
**     }
**     printf( "\n" );
** 
**     return 0;
** }
*/