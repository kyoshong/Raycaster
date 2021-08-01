/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:42:49 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/31 21:42:53 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_floor_val(t_horizon *horizon, t_info *info)
{
	horizon->rayDirX0 = info->dirX - info->planeX;
	horizon->rayDirY0 = info->dirY - info->planeY;
	horizon->rayDirX1 = info->dirX + info->planeX;
	horizon->rayDirY1 = info->dirY + info->planeY;
	horizon->p = horizon->y - info->height / 2;
	horizon->posZ = 0.5 * info->height;
	horizon->rowDistance = horizon->posZ / horizon->p;
	horizon->floorStepX = horizon->rowDistance * (horizon->rayDirX1 - horizon->rayDirX0) / info->width;
	horizon->floorStepY = horizon->rowDistance * (horizon->rayDirY1 - horizon->rayDirY0) / info->width;
	horizon->floorX = info->posX + horizon->rowDistance * horizon->rayDirX0;
	horizon->floorY = info->posY + horizon->rowDistance * horizon->rayDirY0;
}

void	print_floor_ceilling(t_info *info)
{
	t_horizon horizon;

	horizon.y = info->height / 2 + 1;
	while (horizon.y < info->height)
	{
		set_floor_val(&horizon, info);
		horizon.x = 0;
		while (horizon.x < info->width)
		{
			horizon.cellX = (int)horizon.floorX;
			horizon.cellY = (int)horizon.floorY;
			horizon.tx = (int)(textWidth * (horizon.floorX - horizon.cellX)) & (textWidth - 1);
			horizon.ty = (int)(textHeight * (horizon.floorY - horizon.cellY)) & (textHeight - 1);
			horizon.floorX += horizon.floorStepX;
			horizon.floorY += horizon.floorStepY;
			horizon.color = info->config->ceiling;
			//floor.color = info->texture[6][textWidth * floor.ty + floor.tx];
			//horizon.color = (horizon.color >> 1) & 8355711;
			info->buf[horizon.y][horizon.x] = horizon.color;
			horizon.color = info->config->floor;
			//horizon.color = info->texture[5][textWidth * horizon.ty + horizon.tx];
			//horizon.color = (horizon.color >> 2) & 8355711;
			info->buf[info->height - horizon.y - 1][horizon.x] = horizon.color;
			horizon.x++;
		}
		horizon.y++;
	}
}
