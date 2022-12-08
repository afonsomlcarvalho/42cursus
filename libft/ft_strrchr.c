/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:46:50 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/03 12:20:27 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	i = ft_strlen(s);
	c1 = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == c1)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
