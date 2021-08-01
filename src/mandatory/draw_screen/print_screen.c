/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:37:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/31 21:44:58 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_dir(t_info *info, t_wall *wall)
{
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

void	cal_distance(t_info *info, t_wall *wall)
{
	wall->mapX = (int)info->posX;
	wall->mapY = (int)info->posY; //현재위치 자연수
	wall->deltaDistX = fabs(1 / wall->rayDirX);
	wall->deltaDistY = fabs(1 / wall->rayDirY);
	wall->hit = 0;
	ray_dir(info, wall);
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
