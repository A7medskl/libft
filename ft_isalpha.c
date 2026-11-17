/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:43:08 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 10:43:08 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
/*
** 
** #include <stdio.h>
** 
** int main(void)
** {
**     int result1 = ft_isalpha('A'); // Should return 1 (true)
**     int result2 = ft_isalpha('z'); // Should return 1 (true)
**     int result3 = ft_isalpha('1'); // Should return 0 (false)
**     int result4 = ft_isalpha('@'); // Should return 0 (false)
** 
**     printf("ft_isalpha('A'): %d\n", result1);
**     printf("ft_isalpha('z'): %d\n", result2);
**     printf("ft_isalpha('1'): %d\n", result3);
**     printf("ft_isalpha('@'): %d\n", result4);
** 
**     return 0;
** }
*/