#include "cub3d.h"

t_info	set_config(t_config *config)
{
	t_info info;

	info.mlx = mlx_init();
	info.width = config->width;
	info.height = config->height;
	info.posX = 22.0;
	info.posY = 11.5;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.planeY = 0.66;
	info.key_a = 0;
	info.key_w = 0;
	info.key_s = 0;
	info.key_d = 0;
	info.key_esc = 0;
	return (info);
}