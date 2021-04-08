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

	t_player	t_player;
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


int main()
{
	t_window window;

	window.width = 500;
	window.hight = 500;
	window.grid_color = 0x00FFFF;
	window.row_count = 10;
	window.column_count = 10;
	
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.hight, "mlx_grid");
	mlx_loop_hook(window.mlx, draw_grid, &window);
	mlx_loop(window.mlx);
	return 0;
}
