#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param{
	float	x;
	float	y;
	char	str[3];
}				t_param;

void			param_init(t_param *param)
{
	param->x = 50;
	param->y = 50;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_D)
		param->y++;
	else if (keycode == KEY_A)
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
	param_init(&param);

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "wow");
	img = mlx_xpm_file_to_image(mlx, "wall_n.xpm", &img_width, &img_height);
	mlx_hook(win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &param);
	mlx_put_image_to_window(mlx, win, img, 	param.y, 	param.y);
	mlx_loop(mlx);
	return (0);
}
