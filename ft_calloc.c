/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:31:09 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:50:23 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize)
{
	void	*res;

	if (elementSize != 0 && elementCount > (size_t)-1 / elementSize)
		return (NULL);
	res = malloc(elementCount * elementSize);
	if (!res)
	{
		return (NULL);
	}
	ft_bzero(res, elementCount * elementSize);
	return (res);
}
/*
** #include <stdio.h>
** #include <stdlib.h>
** #include <assert.h>
** 
** #define INT_NUMBER 33
** 
** int main() {
** 
**     int i;
**     int * pointer = (int *) ft_calloc( INT_NUMBER, sizeof(int) );
** 
**     assert( pointer != NULL );
** 
**     for (i=0; i<INT_NUMBER; i++ ) {
**         printf( "%d ", pointer[i] );
**     }
**     printf( "\n" );
** 
**     free( pointer );
** 
**     return 0;
** }
*/