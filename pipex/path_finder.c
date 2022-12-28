/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:39:33 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/27 12:01:34 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_paths(char *str)
{
	int	i;
	int	c;

	i = 5;
	c = 0;
	while (str[i])
	{
		if (str[i++] == ':' && str[i] != ':')
			c++;
	}
	return (c + 1);
}

int	path_size(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] && str[i + j] != ':')
		j++;
	return (j);
}

char	*appends(char *path, char *command)
{
	int		i;
	int		j;
	char	*full;

	full = malloc(ft_strlen(path) + ft_strlen(command) + 2);
	i = 0;
	j = 0;
	while (path[i])
	{
		full[i] = path[i];
		i++;
	}
	full[i] = '/';
	i++;
	while (command[j])
	{
		full[i + j] = command[j];
		j++;
	}
	full[i + j] = '\0';
	free (path);
	return (full);
}

char	**path_split(char *str, char *command)
{
	int		i;
	int		j;
	int		x;
	char	**paths;

	paths = malloc(sizeof(char *) * (count_paths(str) + 1));
	j = 5;
	i = 0;
	while (i < count_paths(str))
	{
		x = 0;
		paths[i] = malloc(path_size(str, j) + 1);
		while (path_size(str, j))
		{
			paths[i][x] = str[j];
			x++;
			j++;
		}
		paths[i][x] = '\0';
		if (command)
			paths[i] = appends(paths[i], command);
		i++;
		j++;
	}
	paths[i] = 0;
	return (paths);
}

char	*path_finder(char **env, char *command)
{
	char	*env_path;
	char	*path;
	char	**paths;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			env_path = env[i];
		i++;
	}
	i = 0;
	paths = path_split(env_path, command);
	while (paths[i])
	{
		if (access(paths[i], F_OK) == 0)
			path = paths[i];
		else
			free(paths[i]);
		i++;
	}
	free(paths);
	if (!path)
		path = "Error";
	return (path);
}
