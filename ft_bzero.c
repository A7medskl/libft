/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:04:23 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 13:11:29 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (!s)
		return ;
	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
** #include <stdio.h>
** #include <strings.h>
** 
** int main(void) {
**     char buffer[10] = "Bonjour";
**     printf("%s\n",buffer);
**     // Remplit les 10 octets de buffer avec des '0'
**     ft_bzero(buffer, sizeof(buffer));
** 	printf("%s\n",buffer);
**     return 0;
** 
** }
*/