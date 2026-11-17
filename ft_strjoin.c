/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asakli <asakli@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:30:35 by asakli            #+#    #+#             */
/*   Updated: 2026/11/03 15:47:08 by asakli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	res = malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!res)
	{
		return (NULL);
	}
	ft_strlcpy(res, s1, ls1 + 1);
	ft_strlcat(res, s2, ls1 + ls2 + 1);
	return (res);
}
