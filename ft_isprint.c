/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:53:38 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 10:53:38 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
** #include <stdio.h>
** int main(void)
** {
**     int result1 = ft_isprint('A'); // Should return 1 (true)
**     int result2 = ft_isprint(' '); // Should return 1 (true)
**     int result3 = ft_isprint(127); // Should return 0 (false)
**     int result4 = ft_isprint(31);  // Should return 0 (false)
** 
**     printf("ft_isprint('A'): %d\n", result1);
**     printf("ft_isprint(' '): %d\n", result2);
**     printf("ft_isprint(127): %d\n", result3);
**     printf("ft_isprint(31): %d\n", result4);
** 
**     return 0;
** }
*/