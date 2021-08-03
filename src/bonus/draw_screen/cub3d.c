/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:37 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/03 18:23:04 by hyospark         ###   ########.fr       */
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
	dda(info, 0, 0);
	mini_map(info);
	draw(info);
	key_update(info);
	return (0);
}
void	mouse_move(t_info *info)
{
	
}

void	start_cub3d(t_config *config)
{
	t_info info;

	set_config(config, &info);
	set_buf(&info);
	set_texture(&info, 0, 0);
	load_texture(&info);
	info.win = mlx_new_window(info.mlx, info.width, info.height, "cub3d");
	info.img.img = mlx_new_image(info.mlx, info.width, info.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, \
	&info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, KEY_RELEASE, 0, &key_release, &info);
	mlx_hook(info.win, MOUSE_MOVE, 0, &mouse_move, &info);

	mlx_loop(info.mlx);
}
