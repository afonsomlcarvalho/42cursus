/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:58:46 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/03 12:14:11 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	i = -1;
	c1 = (unsigned char)c;
	while (s[++i])
	{
		if (s[i] == c1)
			return ((char *)(s + i));
	}
	if (s[i] == c1)
		return ((char *)(s + i));
	return (NULL);
}
