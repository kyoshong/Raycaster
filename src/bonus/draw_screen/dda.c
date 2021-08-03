/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 23:03:39 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/02 17:48:20 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cal_dda(t_info *info, t_wall *wall)
{
	wall->rayDirX = info->dirX + info->planeX * wall->cameraX;
	wall->rayDirY = info->dirY + info->planeY * wall->cameraX;
	cal_distance(info, wall);
	check_hit(info, wall);
	set_textureNum(wall);
	get_ratio(info, wall);
}

void	dda(t_info *info, int x, int i)
{
	t_wall wall;

	print_floor_ceilling(info);
	while (x < info->width)
	{
		wall.cameraX = 2 * x / (double)info->width - 1;
		cal_dda(info, &wall);
		i = wall.drawStart;
		while (i < wall.drawEnd)
		{
			wall.texY = (int)wall.texPos & (textHeight - 1);
			wall.texPos += wall.step;
			wall.color = info->texture[wall.textNum][textHeight * wall.texY + wall.texX];
			if (wall.side == 1)
				wall.color = (wall.color >> 1) & 8355711;
			info->buf[i][x] = wall.color;
			i++;
		}
		info->zBuffer[x] = wall.perpWallDist;
		x++;
	}
}
