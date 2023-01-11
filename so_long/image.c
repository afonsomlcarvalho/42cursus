#include "flag.h"

int	move(int keycode, t_vars *vars)
{
	if (keycode == 65363)
	{
		vars->moves.x += 20;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->master.walk_right.img, 500 + vars->moves.x, 500 + vars->moves.y);
	}
	else if (keycode == 65361)
	{
		vars->moves.x -= 20;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->master.walk_left.img, 500 + vars->moves.x, 500 + vars->moves.y);
	}
	else if (keycode == 65362)
	{
		vars->moves.y -= 20;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->master.walk_up.img, 500 + vars->moves.x, 500 + vars->moves.y);
	}
	else if (keycode == 65364)
	{
		vars->moves.y += 20;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->master.walk_down.img, 500 + vars->moves.x, 500 + vars->moves.y);
	}
	return (0);
}

int	main()
{
	t_vars	vars;
	
	vars.mlx = mlx_init();
	vars.moves.x = 0;
	vars.moves.y = 0;
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Janela");
	vars.master.walk_down.path = "./Walk_down.xpm";
	vars.master.walk_left.path = "./Walk_left.xpm";
	vars.master.walk_right.path = "./Walk_right.xpm";
	vars.master.walk_up.path = "./Walk_up.xpm";
	vars.master.walk_down.img = mlx_xpm_file_to_image(vars.mlx, vars.master.walk_down.path, &vars.master.walk_down.width, &vars.master.walk_down.height);
	vars.master.walk_left.img = mlx_xpm_file_to_image(vars.mlx, vars.master.walk_left.path, &vars.master.walk_left.width, &vars.master.walk_left.height);
	vars.master.walk_right.img = mlx_xpm_file_to_image(vars.mlx, vars.master.walk_right.path, &vars.master.walk_right.width, &vars.master.walk_right.height);
	vars.master.walk_up.img = mlx_xpm_file_to_image(vars.mlx, vars.master.walk_up.path, &vars.master.walk_up.width, &vars.master.walk_up.height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.master.walk_down.img, 500, 500);
	mlx_key_hook(vars.win, move, &vars);
	mlx_loop(vars.mlx);
}