/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:37 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 00:27:50 by hyospark         ###   ########.fr       */
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



int	main_loop(t_info *info, t_config *config)
{
	calc(info);
	draw(info);
	key_update(info, config);
	return (0);
}

int	main_loop(t_info *info, t_config *config)
{
	calc(info);
	for (int y = 0; y < info->height; y++)
	{
		for (int x = 0; x < info->width; x++)
			info->img.data[y * info->width + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	key_update(info, config);
	return (0);
}

int		start_cub3d(t_config *config)
{
	t_info info;
	
	info = set_config();
	load_texture(&info);
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;

	info.win = mlx_new_window(info.mlx, info.width, info.height, "cub3d");

	info.img.img = mlx_new_image(info.mlx, info.width, info.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);

	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);

	mlx_loop(info.mlx);
}
