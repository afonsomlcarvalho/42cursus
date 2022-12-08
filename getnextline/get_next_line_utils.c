/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:45:55 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/21 10:32:13 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_strjoin(char *line, char *text)
{
	char	*joined;
	int		i;

	i = 0;
	joined = malloc(ft_strlen(line) + ft_strlen(text) + 1);
	if (!joined)
		return (NULL);
	while (line && line[i])
	{
		joined[i] = line[i];
		i++;
	}
	while (*text)
	{
		joined[i++] = *text;
		if (*text++ == '\n')
			break ;
	}
	joined[i] = '\0';
	free(line);
	return (joined);
}

int	clear(char *text)
{
	int	n;
	int	i;
	int	j;

	i = 0;
	j = 0;
	n = 0;
	while (text[i])
	{
		if (n == 1)
			text[j++] = text[i];
		if (text[i] == '\n')
			n = 1;
		text[i++] = 0;
	}
	return (n);
}
