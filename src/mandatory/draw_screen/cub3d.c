/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:37 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/24 19:51:00 by hyospark         ###   ########.fr       */
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

void	set_config(t_config *config, t_info *info)
{
	if ((info->mlx = mlx_init()) == NULL)
		free_map_error_exit(config->map, "MLX_INIT_ERROR");
	info->width = 640;
	info->height = 480;
	info->posX = config->player.x;
	info->posY = config->player.y;
	info->dirX = -1.0;
	info->dirY = 0.0;
	info->planeX = 0.0;
	info->planeY = 0.66;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;
	info->config = config;
}

void	set_texture(t_info *info)
{
	int i;
	int j;
	
	i = 0;
	info->buf = (int **)malloc(sizeof(int*) * 480);
	while (i < info->height)
	{
		j = 0;
		info->buf[i] = (int *)malloc(sizeof(int) * 640);
		while (j < info->width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!(info->texture = (int **)malloc(sizeof(int *) * 11)))
		return ;
	i = 0;
	while (i < 11)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (textHeight * textWidth))))
			return ;
		i++;
	}
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < textHeight * textWidth)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	start_cub3d(t_config *config)
{
	t_info info;

	set_config(config, &info);
	set_texture(&info);
	load_texture(&info);
	printf("%d %d", config->player.x, config->player.y);
	info.win = mlx_new_window(info.mlx, info.width, info.height, "cub3d");
	info.img.img = mlx_new_image(info.mlx, info.width, info.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, \
	&info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_loop(info.mlx);
}
