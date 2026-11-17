/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:05:19 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 14:50:16 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	len;
	int	res;
	int	signe;

	if (!nptr)
		return (0);
	len = 0;
	res = 0;
	signe = 1;
	while ((nptr[len] >= 9 && nptr[len] <= 13) || nptr[len] == ' ')
		len++;
	if (nptr[len] == '-' || nptr[len] == '+')
	{
		if (nptr[len] == '-')
			signe = -1;
		len++;
	}
	while (ft_isdigit(nptr[len]))
	{
		res = res * 10 + (nptr[len] - '0');
		len++;
	}
	return (res * signe);
}
/*
** #include <stdio.h>
** #include <strings.h>
** int main(void)
** {
** 	printf("ft_atoi(42) : %d \n",ft_atoi("42"));
** 	printf("ft_atoi(-42) : %d \n",ft_atoi("-42"));
** 	printf("ft_atoi(    -42) : %d \n",ft_atoi("    -42"));
** 	printf("ft_atoi(abc42) : %d \n",ft_atoi("abc42"));
** 	printf("ft_atoi(42abc) : %d \n",ft_atoi("42abc"));
** 	printf("ft_atoi(0) : %d \n",ft_atoi("0"));
** 	printf("ft_atoi(abc) : %d \n",ft_atoi("abc"));
** 	return 0;
** }
*/