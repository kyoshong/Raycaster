/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:37:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/30 23:40:51 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cal_distance(t_info *info, t_wall *wall)
{
	wall->mapX = (int)info->posX;
	wall->mapY = (int)info->posY; //현재위치 자연수
	wall->deltaDistX = fabs(1 / wall->rayDirX);
	wall->deltaDistY = fabs(1 / wall->rayDirY);
	wall->hit = 0;
	if (wall->rayDirX < 0)
	{
		wall->stepX = -1;
		wall->sideDistX = (info->posX - wall->mapX) * wall->deltaDistX;
	}
	else
	{
		wall->stepX = 1;
		wall->sideDistX = (wall->mapX + 1.0 - info->posX) * wall->deltaDistX;
	}
	if (wall->rayDirY < 0)
	{
		wall->stepY = -1;
		wall->sideDistY = (info->posY - wall->mapY) * wall->deltaDistY;
	}
	else
	{
		wall->stepY = 1;
		wall->sideDistY = (wall->mapY + 1.0 - info->posY) * wall->deltaDistY;
	}
}

void	check_hit(t_info *info, t_wall *wall)
{
	while (!wall->hit)
	{
		if (wall->sideDistX < wall->sideDistY)
		{
			wall->sideDistX += wall->deltaDistX;
			wall->mapX += wall->stepX;
			wall->side = 0;
		}
		else
		{
			wall->sideDistY += wall->deltaDistY;
			wall->mapY += wall->stepY;
			wall->side = 1;
		}
		if (info->config->worldMap[wall->mapX][wall->mapY] > 0)
			wall->hit = 1;
	}
	if (wall->side == 0)
		wall->perpWallDist = (wall->mapX - info->posX + (1 - wall->stepX) / 2) / wall->rayDirX;
	else
		wall->perpWallDist = (wall->mapY - info->posY + (1 - wall->stepY) / 2) / wall->rayDirY;
}

void	get_ratio(t_info *info, t_wall *wall)
{
	wall->lineHeight = (int)(info->height / wall->perpWallDist);
	wall->drawStart = -wall->lineHeight / 2 + info->height / 2;
	if (wall->drawStart < 0)
		wall->drawStart = 0;
	wall->drawEnd = wall->lineHeight / 2 + info->height / 2;
	if (wall->drawEnd >= info->height)
		wall->drawEnd = info->height - 1;
	if (wall->side == 0)
		wall->wallX = info->posY + wall->perpWallDist * wall->rayDirY;
	else
		wall->wallX = info->posX + wall->perpWallDist * wall->rayDirX;
	wall->wallX -= floor(wall->wallX);
	wall->texX = (int)(wall->wallX * (double)textWidth);
	if (wall->side == 0 && wall->rayDirX > 0)
		wall->texX = textWidth - wall->texX - 1;
	if (wall->side == 1 && wall->rayDirY < 0)
		wall->texX = textWidth - wall->texX - 1;
	wall->step = 1.0 * textHeight / wall->lineHeight;
	wall->texPos = (wall->drawStart - info->height / 2 + wall->lineHeight / 2) * wall->step;
}

void	set_textureNum(t_wall *wall)
{
	if (!wall->side && wall->stepX < 0)
		wall->textNum = 4;
	else if (!wall->side && wall->stepX >= 0)
		wall->textNum = 5;
	else if (wall->side && wall->stepY < 0)
		wall->textNum = 6;
	else if (wall->side && wall->stepY >= 0)
		wall->textNum = 7;
}

void	cal_dda(t_info *info)
{
	print_floor_ceilling(info);
	int x = 0;
	int i;
	t_wall wall;
	while (x < info->width)
	{
		wall.cameraX = 2 * x / (double)info->width - 1;
		wall.rayDirX = info->dirX + info->planeX * wall.cameraX;
		wall.rayDirY = info->dirY + info->planeY * wall.cameraX;
		cal_distance(info, &wall);
		check_hit(info, &wall);
		set_textureNum(&wall);
		get_ratio(info, &wall);
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
