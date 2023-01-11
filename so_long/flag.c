#include "flag.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_square(t_data *data, t_coords p, t_coords size, int	color)
{
	int	start_x;

	while(size.y >= 0)
	{
		start_x = size.x;
		while (start_x >= 0)
		{
			my_mlx_pixel_put(data, p.x + start_x, p.y + size.y, color);
			start_x--;
		}
		size.y--;
	}
}

void	put_circle(t_data *data, t_coords center, int radius, int color)
{
	t_coords	start;
	t_coords	end;
	int	start_x;

	start.x = center.x - radius;
	start.y = center.y - radius;
	end.x = center.x + radius;
	end.y = center.y + radius;
	while (start.y <= end.y)
	{
		start_x = start.x;
		while (start_x <= end.x)
		{
			if (pow(start_x - center.x, 2) + pow(start.y - center.y, 2) <= pow(radius, 2))
				my_mlx_pixel_put(data, start_x, start.y, color);
			start_x++;
		}
		start.y++;
	}
}

void	draw_flag(t_coords start, t_coords size, t_vars vars)
{
	t_data	img;
	t_coords	size_square;

	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	size_square.x = size.x / 3;
	size_square.y = size.y;
	put_square(&img, start, size_square, 0x0000dd00);
	start.x += size_square.x;
	size_square.x *= 1.3;
	put_square(&img, start, size_square, 0x00FF0000);
	start.y += (size.y - start.y) / 2 + vars.moves.y;
	start.x += vars.moves.x;
	put_circle(&img, start, size.y / 4, 0x00FFFF00);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}

int	move_flag(int keycode, t_vars *vars)
{
	if (keycode == 65363)
		vars->moves.x += 20;
	else if (keycode == 65361)
		vars->moves.x -= 20;
	else if (keycode == 65362)
		vars->moves.y -= 20;
	else if (keycode == 65364)
		vars->moves.y += 20;
	else if (keycode == 65307)
	{
		mlx_destroy_window((*vars).mlx, (*vars).win);
		exit(0);
	}
	draw_flag(vars->start, vars->size, *vars);
	return (0);
}

/* int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Flag");
	vars.start.x = 5;
	vars.start.y = 5;
	vars.size.x = 400;
	vars.size.y = 170;
	vars.moves.x = 0;
	vars.moves.y = 0;
	draw_flag(vars.start, vars.size, vars);
	mlx_key_hook(vars.win, move_flag, &vars);	
	mlx_loop(vars.mlx);
} */