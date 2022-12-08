/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:37:09 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/02 12:40:35 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		x;

	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	x = -1;
	if (!join)
		return (NULL);
	while (s1[++x])
	{
		join[i] = s1[x];
		i++;
	}
	x = -1;
	while (s2[++x])
	{
		join[i] = s2[x];
		i++;
	}
	join[i] = '\0';
	return (join);
}
