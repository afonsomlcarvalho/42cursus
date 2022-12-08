/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:47:27 by amorais-          #+#    #+#             */
/*   Updated: 2022/10/27 14:50:17 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;
	char	*big1;

	big1 = (char *)big;
	i = 0;
	x = 0;
	if (little[x] == '\0')
		return (big1);
	if (len == 0)
		return (NULL);
	while (big1[i] && i < len)
	{
		while (big1[i + x] && little[x] == big1[i + x] && (i + x < len))
			x++;
		if (little[x] == '\0')
			return (big1 + i);
		i++;
		x = 0;
	}	
	return (NULL);
}
/*
int	main()
{
	char *s1 = "MZIRIBMZIRIBMZE123";
	char *s2 = "MZIRIBMZE";
	size_t max = ft_strlen(s2);
	printf("%s\n", ft_strnstr(s1, s2, max));
}
*/