/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:07:38 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/12 16:30:50 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*line_join(char	*line, char	*gnl)
{
	char	*new_line;
	int	i;
	int	j;

	if (!line)
		return (gnl);
	new_line = malloc(ft_strlen(line) + ft_strlen(gnl) + 1);
	i = -1;
	j = -1;
	while (line[++i])
		new_line[i] = line[i];
	while (gnl[++j])
		new_line[i + j] = gnl[j];
	new_line[i + j] = '\0';
	if (line)
		free(line);
	free(gnl);
	return (new_line);
}

int	coord_management(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
	{
		map->master.position.x = j + 1;
		map->master.position.y = i + 1;
	}
	else if (map->map[i][j] == 'E')
	{
		map->exit.position.x = j + 1;
		map->exit.position.y = i + 1;
	}
	else if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'C')
		return (-1);
	return (0);
}

int	map_setup(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			if (coord_management(map, i, j++) == -1)
				return (-1);
		if (j != map->dimension.x)
			return (-1);
		i++;
	}
	return (0);
}

t_map	map_creator(char *map_name)
{
	t_map	map;
	char	*line;
	char	*gnl;

	map.fd = open(map_name, O_RDONLY);
	if (!map.fd)
		return (map);
	gnl = get_next_line(map.fd);
	line = NULL;
	map.dimension.y = 0;
	while (gnl)
	{
		line = line_join(line, gnl);
		gnl = get_next_line(map.fd);
		map.dimension.y++;
	}
	map.map = ft_split(line, '\n');
	map.dimension.x = ft_strlen(map.map[0]);
	free(line);
	if (map_setup(&map) == -1)
		write(2, "Error\n", 6);
	return (map);
}

void	map_clear(t_map	map)
{
	int	i;

	i = 0;
	while(map.map[i])
		free(map.map[i++]);
	free(map.map);
}

int	main()
{
	t_map	map;

	map = map_creator("map.ber");
	printf("master is at (%d, %d).\nexit is at (%d, %d)\n", map.master.position.x, map.master.position.y, map.exit.position.x, map.exit.position.y);
	map_clear(map);
}
