/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:48:28 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/03 11:55:36 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;
	char			*t1;
	char			*t2;

	if (n == 0)
		return (0);
	t1 = (char *) s1;
	t2 = (char *) s2;
	i = 0;
	while (t1[i] == t2[i] && i + 1 < n)
		i++;
	c1 = t1[i];
	c2 = t2[i];
	return (c1 - c2);
}
