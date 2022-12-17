/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:25:54 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/04 14:54:38 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_beg(char const *s1, char const *set)
{
	int		i;
	size_t	x;
	size_t	c;

	i = 0;
	x = 0;
	c = 0;
	while (s1[i])
	{
		while (set[x])
		{
			if (set[x] == s1[i])
			{
				c++;
				break ;
			}
			x++;
		}
		i++;
		if (x == ft_strlen(set))
			break ;
		x = 0;
	}
	return (c);
}

size_t	count_end(char const *s1, char const *set)
{
	int		i;
	size_t	x;
	size_t	c;

	i = ft_strlen(s1) - 1;
	x = 0;
	c = 0;
	while (i >= 0)
	{
		while (set[x])
		{
			if (set[x] == s1[i])
			{
				c++;
				break ;
			}
			x++;
		}
		i--;
		if (x == ft_strlen(set))
			break ;
		x = 0;
	}
	return (c);
}

char	*caseblank(void)
{
	char	*s;

	s = malloc(sizeof(char));
	s[0] = '\0';
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*end;
	int			i;
	size_t		x;

	if (count_beg(s1, set) == ft_strlen(s1))
		return (caseblank());
	end = malloc(sizeof(char) * (ft_strlen(s1) + 1 - count_beg(s1, set) \
	- count_end(s1, set)));
	if (!end)
		return (NULL);
	i = 0;
	x = count_beg(s1, set);
	while (x < (ft_strlen(s1) - count_end(s1, set)))
	{
		end[i] = s1[x];
		i++;
		x++;
	}
	end[i] = '\0';
	return (end);
}
