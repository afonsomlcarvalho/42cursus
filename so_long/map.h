#ifndef MAP_H
# define MAP_H

# include "getnextline/get_next_line.h"
# include "flag.h"

typedef	struct s_map
{
	char		**map;
	t_coords	dimension;
	int			fd;
	t_master	master;
	t_master	exit;
}				t_map;

t_map	map_creator(char *map_name);
int		map_validator(t_map	map);
#endif