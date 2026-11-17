/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:48:23 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:58:10 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup( const char *source)
{
	size_t	len;
	char	*res;

	if (!source)
		return (NULL);
	len = ft_strlen(source) + 1;
	res = malloc(len * sizeof(char));
	if (!res)
	{
		return (NULL);
	}
	ft_strlcpy(res, source, len);
	return (res);
}
/*
** #include <ctype.h>
** #include <stdio.h>
** #include <stdlib.h>
** #include <string.h>
** 
** 
** int main() {
** 
**     const char * original = "The original string.";
** 
**     // On duplique la chaîne de caractères initiale.
**     char * copy = ft_strdup( original );
** 
**     // On passe chaque lettre en majuscule.
**     char * ptr = copy;
**     while( *ptr != '\0' ) {
**         *ptr = toupper( *ptr );
**         ptr++;
**     }
** 
**     // On affiche la chaîne finale
**     printf( "%s\n", copy );
** 
**     // Sans oublier de libérer l'espace mémoire au final.
**     free( copy );
** 
**     return EXIT_SUCCESS;
** }
** 
*/
