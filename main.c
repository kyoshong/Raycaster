#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS		2
#define FORWORD					126
#define BACK					125
#define RIGHT					124
#define LEFT					123
#define KEY_ESC			53

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;

void			param_init(t_param *param)
{
	param->x = 50;
	param->y = 50;
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == FORWORD)
		param->x++;
	else if (keycode == BACK)
		param->x--;
	else if (keycode == RIGHT)
		param->y++;
	else if (keycode == LEFT)
		param->y--;
	else if (keycode == KEY_ESC)
		exit(0);
	
	return (0);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	void *img;
	int		img_width;
	int 	img_height;
	t_param		param;
	mlx = mlx_init();
	//param_init(&param);
	//win = mlx_new_window(mlx, 500, 500, "mlx_project");
	img = mlx_xpm_file_to_image(mlx, "wall.jpeg", &img_width, &img_height);
	//mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_put_image_to_window(mlx, win, img, param.x, param.y);
	mlx_loop(mlx);
	return (0);
}