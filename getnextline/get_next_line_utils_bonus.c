/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:35:22 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/17 13:50:52 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int	post_nl_len(char *str)
{
	int	i;
	int	l;

	if (!ft_strchr(str, '\n'))
		return (0);
	i = 0;
	l = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i + l])
		l++;
	return (l);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*joined;

	joined = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!joined)
		return (NULL);
	i = -1;
	j = 0;
	while (str1[++i])
	{
		joined[j] = str1[i];
		j++;
	}
	i = -1;
	while (str2[++i])
	{
		joined[j] = str2[i];
		j++;
	}
	joined[j] = '\0';
	return (joined);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joined;

	if (!str1 && str2)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	joined = ft_strjoin2(str1, str2);
	free(str1);
	return (joined);
}
