/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:37:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/13 20:05:07 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_dir(t_info *info, t_wall *wall)
{
	if (wall->rayDirX < 0)
	{
		wall->stepX = -1;
		wall->firstDistX = (info->posX - wall->mapX) * wall->nextDistX;
	}
	else
	{
		wall->stepX = 1;
		wall->firstDistX = (wall->mapX + 1.0 - info->posX) * wall->nextDistX;
	}
	if (wall->rayDirY < 0)
	{
		wall->stepY = -1;
		wall->firstDistY = (info->posY - wall->mapY) * wall->nextDistY;
	}
	else
	{
		wall->stepY = 1;
		wall->firstDistY = (wall->mapY + 1.0 - info->posY) * wall->nextDistY;
	}
}

void	cal_distance(t_info *info, t_wall *wall)
{
	wall->mapX = (int)info->posX;
	wall->mapY = (int)info->posY;
	wall->nextDistX = fabs(1 / wall->rayDirX);
	wall->nextDistY = fabs(1 / wall->rayDirY);
	wall->hit = 0;
	ray_dir(info, wall);
}

void	check_hit(t_info *info, t_wall *wall)
{
	while (!wall->hit)
	{
		if (wall->firstDistX < wall->firstDistY)
		{
			wall->firstDistX += wall->nextDistX;
			wall->mapX += wall->stepX;
			wall->side = 0;
		}
		else
		{
			wall->firstDistY += wall->nextDistY;
			wall->mapY += wall->stepY;
			wall->side = 1;
		}
		if (info->config->worldMap[wall->mapX][wall->mapY] == 1)
			wall->hit = 1;
	}
	if (wall->side == 0)
		wall->flatWallDist = (wall->mapX - info->posX + \
		(1 - wall->stepX) / 2) / wall->rayDirX;
	else
		wall->flatWallDist = (wall->mapY - info->posY + \
		(1 - wall->stepY) / 2) / wall->rayDirY;
}

void	get_ratio(t_info *info, t_wall *wall)
{
	wall->lineHeight = (int)(info->height / wall->flatWallDist);
	wall->drawStart = -wall->lineHeight / 2 + info->height / 2;
	if (wall->drawStart < 0)
		wall->drawStart = 0;
	wall->drawEnd = wall->lineHeight / 2 + info->height / 2;
	if (wall->drawEnd >= info->height)
		wall->drawEnd = info->height - 1;
	if (wall->side == 0)
		wall->wallX = info->posY + wall->flatWallDist * wall->rayDirY;
	else
		wall->wallX = info->posX + wall->flatWallDist * wall->rayDirX;
	wall->wallX -= floor(wall->wallX);
	wall->texX = (int)(wall->wallX * (double)TEXT_HEIGHT);
	if (wall->side == 0 && wall->rayDirX > 0)
		wall->texX = TEXT_WIDTH - wall->texX - 1;
	if (wall->side == 1 && wall->rayDirY < 0)
		wall->texX = TEXT_WIDTH - wall->texX - 1;
	wall->step = 1.0 * TEXT_HEIGHT / wall->lineHeight;
	wall->texPos = (wall->drawStart - info->height / \
	2 + wall->lineHeight / 2) * wall->step;
}

void	set_textureNum(t_wall *wall)
{
	if (!wall->side && wall->stepX < 0)
		wall->textNum = 0;
	else if (wall->side && wall->stepY >= 0)
		wall->textNum = 1;
	else if (wall->side && wall->stepY < 0)
		wall->textNum = 2;
	else if (!wall->side && wall->stepX >= 0)
		wall->textNum = 3;
}
