#include "mlx.h"

#define X_EVENT_KEY_PRESS		2


int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);

	mlx_loop(mlx);
}
