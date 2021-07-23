/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:37 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 23:02:57 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(t_info *info)
{
	for (int y = 0; y < info->height; y++)
	{
		for (int x = 0; x < info->width; x++)
			info->img.data[y * info->width + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}


int	main_loop(t_info *info)
{
	cal_dda(info);
	draw(info);
	key_update(info);
	return (0);
}

// int	main_loop(t_info *info)
// {
// 	cal_dda(info);
// 	for (int y = 0; y < info->height; y++)
// 	{
// 		for (int x = 0; x < info->width; x++)
// 			info->img.data[y * info->width + x] = info->buf[y][x];
// 	}
// 	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
// 	key_update(info);
// 	return (0);
//}

t_info	set_config(t_config *config)
{
	t_info info;

	if ((info.mlx = mlx_init()) == NULL)
		free_map_error_exit(config->map, "MLX_INIT_ERROR");
	info.width = 1920;
	info.height = 1080;
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
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	info.config = config;
	return (info);
}

void	set_cub3d(t_info *info, t_config *config)
{
	info->win = mlx_new_window(info->mlx, info->width, info->height, "cub3d");
	if (info->win == NULL)
		free_map_error_exit(config->map, "NEW_WIN_ERROR");
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	if (info->img.img == NULL)
		free_map_error_exit(config->map, "NEW_WIN_ERROR");
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, \
	&info->img.size_l, &info->img.endian);
}

void	start_cub3d(t_config *config)
{
	t_info info;

	info = set_config(config);
	load_texture(&info);
	set_cub3d(&info, config);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_loop(info.mlx);
}
