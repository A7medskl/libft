/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:36:58 by asakli            #+#    #+#             */
/*   Updated: 2026/11/05 13:36:58 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*handle_alloc(int len, int n)
{
	char	*str;

	if (n < 0)
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
		n = -n;
	}
	else
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = count_digits(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = handle_alloc(len, n);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
/*
**
** #include <stdio.h>
**
** int	main(void)
** {
** 	char	*r;
**
** 	r = ft_itoa(42);
** 	printf("%s attendu 42\n", r);
** 	free(r);
** 	r = ft_itoa(-42);
** 	printf("%s attendu -42\n", r);
** 	free(r);
** 	r = ft_itoa(0);
** 	printf("%s attendu 0\n", r);
** 	free(r);
** 	r = ft_itoa(2147483647);
** 	printf("%s attendu 2147483647\n", r);
** 	free(r);
** 	r = ft_itoa(-2147483648);
** 	printf("%s attendu -2147483648\n", r);
** 	free(r);
** 	return (0);
** }
*/
