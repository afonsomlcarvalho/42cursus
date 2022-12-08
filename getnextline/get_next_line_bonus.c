/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:35:31 by amorais-          #+#    #+#             */
/*   Updated: 2022/11/17 14:09:37 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_creator(char *text)
{
	int		i;
	char	*line;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i] = '\n';
	else
		line[i] = '\0';
	line[i + 1] = '\0';
	return (line);
}

char	*text_advancer(char *text)
{
	char	*text_advanced;
	int		i;
	int		j;

	if (!post_nl_len(text))
	{
		free(text);
		return (NULL);
	}
	text_advanced = malloc(sizeof(char) * (post_nl_len(text) + 1));
	if (!text_advanced)
		return (NULL);
	i = 0;
	j = 0;
	while (text[j] != '\n')
		j++;
	while (text[++j])
	{
		text_advanced[i] = text[j];
		i++;
	}
	text_advanced[i] = '\0';
	free(text);
	return (text_advanced);
}

char	*reader(int fd, char *text)
{
	char	*temp;
	int		state;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!text || ft_strchr(text, '\n') == 0)
	{
		state = read(fd, temp, BUFFER_SIZE);
		if (state <= 0)
		{
			free(temp);
			if (state < 0)
			{
				free(text);
				return (NULL);
			}
			return (text);
		}
		temp[state] = '\0';
		text = ft_strjoin(text, temp);
	}
	free (temp);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (text[fd] && ft_strchr(text[fd], '\0'))
	{
		line = line_creator(text[fd]);
		text[fd] = text_advancer(text[fd]);
		return (line);
	}
	text[fd] = reader(fd, text[fd]);
	if (!text[fd])
	{
		free(text[fd]);
		return (NULL);
	}
	line = line_creator(text[fd]);
	text[fd] = text_advancer(text[fd]);
	return (line);
}
