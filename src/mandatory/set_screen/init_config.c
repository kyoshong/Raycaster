/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:31:55 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/13 16:53:27 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_config(t_config *config, t_info *info)
{
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		map_avail_error_exit(config, "MLX_INIT_ERROR");
	info->width = 1280;
	info->height = 960;
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

void	set_buf(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->buf = (int **)malloc(sizeof(int *) * info->height);
	if (info->buf == NULL)
		cub3d_error_exit(info, "SCREEN_BUF_MALLOC_ERROR");
	while (i < info->height)
	{
		j = 0;
		info->buf[i] = (int *)malloc(sizeof(int) * info->width);
		if (info->buf[i] == NULL)
		{
			free_arr(info->buf, i - 1);
			cub3d_error_exit(info, "SCREEN_BUF_MALLOC_ERROR");
		}
		while (j < info->width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set_texture(t_info *info, int i, int j)
{
	info->texture = (int **)malloc(sizeof(int *) * PICS_NUM);
	if (info->texture == NULL)
		cub3d_error_exit(info, "TEXTURE_MALLOC_ERROR");
	while (i < PICS_NUM)
	{
		info->texture[i] = \
		(int *)malloc(sizeof(int) * (TEXT_WIDTH * TEXT_HEIGHT));
		if (info->texture[i] == NULL)
		{
			free_arr(info->texture, i - 1);
			cub3d_error_exit(info, "TEXTURE_MALLOC_ERROR");
		}
		i++;
	}
	i = 0;
	while (i < PICS_NUM)
	{
		j = 0;
		while (j < TEXT_WIDTH * TEXT_HEIGHT)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}
