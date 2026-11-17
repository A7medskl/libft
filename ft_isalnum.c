/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:46:20 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 10:46:20 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

/*
** #include <stdio.h>
** int main(void)
** {
**     int result1 = ft_isalnum('A'); // Should return 1 (true)
**     int result2 = ft_isalnum('z'); // Should return 1 (true)
**     int result3 = ft_isalnum('1'); // Should return 1 (true)
**     int result4 = ft_isalnum('@'); // Should return 0 (false)
** 
**     printf("ft_isalnum('A'): %d\n", result1);
**     printf("ft_isalnum('z'): %d\n", result2);
**     printf("ft_isalnum('1'): %d\n", result3);
**     printf("ft_isalnum('@'): %d\n", result4);
** 
**     return 0;
** }
*/