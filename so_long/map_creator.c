/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:07:38 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/12 15:19:26 by amorais-         ###   ########.fr       */
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
	printf("%d\n", map_validator(map));
	map_clear(map);
}
