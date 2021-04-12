#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef	struct s_player
{
	int		x;
	int		y;
	int		color;
}				t_player;

typedef	struct s_window
{
	void		*mlx;
	void		*win;

	t_player	player;
	int			width;
	int			hight;
	
	int			row_count;
	int			column_count;
	int			grid_color;
}				t_window;

int			draw_grid(t_window *window)
{
	int		draw_position;
	int		i;

	i = 1;
	while (i < window->row_count)
	{
		draw_position = 0;
		while (draw_position <= window->width)
		{
			mlx_pixel_put(window->mlx, window->win, draw_position, 
			i * (window->hight / window->row_count), window->grid_color);
			draw_position++;
		}
		i++;
	}
	i = 1;
	while (i < window->column_count)
	{
		draw_position = 0;
		while (draw_position <= window->width)
		{
			mlx_pixel_put(window->mlx, window->win, i * (window->width / window->column_count),
			draw_position, window->grid_color);
			draw_position++;
		}
		i++;
	}
	return (0);
}
void		init_player(t_window *window)
{
	mlx_pixel_put(window->mlx, window->win, window->player.x, window->player.y, window->player.color);
}

void		move_dot_left(t_window *window)
{
	int		old_x = window->player.x;
	int		old_y = window->player.y;
	int black = 0x000000;

	if((0 < window->player.x && window->player.x <= window->width) && 
	(0 < window->player.y && window->player.x <= window->hight))
	{
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		mlx_pixel_put(window->mlx, window->win, --window->player.x, window->player.y, window->player.color);
	}
}

void		move_dot_right(t_window *window)
{
	int		old_x = window->player.x;
	int		old_y = window->player.y;
	int		black = 0x000000;

	if((0 < window->player.x && window->player.x <= window->width) && 
	(0 < window->player.y && window->player.x <= window->hight))
	{
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		mlx_pixel_put(window->mlx, window->win, ++window->player.x, window->player.y, window->player.color);
	}
}

void		move_dot_up(t_window *window)
{
	int		old_x = window->player.x;
	int		old_y = window->player.y;
	int		black = 0x000000;

	if((0 < window->player.x && window->player.x <= window->width) && 
	(0 < window->player.y && window->player.x <= window->hight))
	{
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		mlx_pixel_put(window->mlx, window->win, window->player.x, --window->player.y, window->player.color);
	}
}

void		move_dot_down(t_window *window)
{
	int		old_x = window->player.x;
	int		old_y = window->player.y;
	int		black = 0x000000;

	if((0 < window->player.x && window->player.x <= window->width) && 
	(0 < window->player.y && window->player.x <= window->hight))
	{
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		mlx_pixel_put(window->mlx, window->win, window->player.x, ++window->player.y, window->player.color);
	}
}

int		press_key_for_dot(int key, t_window *window)
{
	if (key == KEY_A)
		move_dot_left(window);
	else if (key == KEY_D)
		move_dot_right(window);
	else if (key == KEY_W)
		move_dot_up(window);
	else if (key == KEY_S)
		move_dot_down(window);
	return (0);
}

int main()
{
	t_window window;

	window.width = 500;
	window.hight = 500;
	window.row_count = 10;
	window.column_count = 10;
	window.grid_color = 0x00FFFF;
	
	window.player.color = 0xFF0000;
	window.player.x = 220;
	window.player.y = 220;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.hight, "mlx_grid");
	init_player(&window);
	mlx_loop_hook(window.mlx, draw_grid, &window);
	mlx_hook(window.win, 2, 1, press_key_for_dot, &window);
	mlx_loop(window.mlx);
	return 0;
}
