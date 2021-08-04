/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:38:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/04 00:57:15 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_map(t_info *info, int x, int y)
{
	int i;
	int j;
	double weight = (double) (255 - 128) / 255;

	x *= 5;
	y *= 5;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			info->buf[x + i][y + j] = weight * 0x000000 + (1 - weight) * info->buf[x + i][y + j];
			j++;
		}
		i++;
	}
}

void	draw_miniplayer(t_info *info)
{
	int i = (int)(info->posX * 5);
	int j = (int)(info->posY * 5);
	int x = 0;
	int y;

	while (x < 5)
	{
		y = 0;
		while (y < 5)
		{
			info->buf[x + i - 2][y + j - 2] = 0xFF0000;
			y++;
		}
		x++;
	}
}

void	mini_map(t_info *info)
{
	int x;
	int y;

	x = 0;
	while (x < info->config->mapHeight + 1)
	{
		y = 0;
		while (y < info->config->mapWidth + 1)
		{
			if (info->config->worldMap[x][y] == 1)
				draw_map(info, x, y);
			y++;
		}
		x++;
	}
	draw_miniplayer(info);
}

