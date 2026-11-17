/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:47:59 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 10:47:59 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
** #include <stdio.h>
** 
** int main(void)
** {
**     int result1 = ft_isascii('A'); // Should return 1 (true)
**     int result2 = ft_isascii(127); // Should return 1 (true)
**     int result3 = ft_isascii(128); // Should return 0 (false)
**     int result4 = ft_isascii(-1);  // Should return 0 (false)
** 
**     printf("ft_isascii('A'): %d\n", result1);
**     printf("ft_isascii(127): %d\n", result2);
**     printf("ft_isascii(128): %d\n", result3);
**     printf("ft_isascii(-1): %d\n", result4);
** 
**     return 0;
** }
*/