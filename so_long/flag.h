#ifndef FLAG_H
# define FLAG_H

# include "mlx_linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct 	s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef	struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*path;
}				t_img;

typedef struct s_master
{
	t_img		walk_up;
	t_img		walk_down;
	t_img		walk_right;
	t_img		walk_left;
	t_coords	position;
	int			status;
}				t_master;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_coords	moves;
	t_coords	start;
	t_coords	size;
	t_master	master;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	paint_background(int x, int y, int color, t_vars vars);
#endif