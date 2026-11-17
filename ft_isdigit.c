/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_isdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:43:59 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 10:43:59 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
**     int result1 = ft_isdigit('1'); // Should return 1 (true)
**     int result2 = ft_isdigit('9'); // Should return 1 (true)
**     int result3 = ft_isdigit('A'); // Should return 0 (false)
**     int result4 = ft_isdigit('@'); // Should return 0 (false)
** 
**     printf("ft_isdigit('1'): %d\n", result1);
**     printf("ft_isdigit('9'): %d\n", result2);
**     printf("ft_isdigit('A'): %d\n", result3);
**     printf("ft_isdigit('@'): %d\n", result4);
** 
**     return 0;
** }
*/