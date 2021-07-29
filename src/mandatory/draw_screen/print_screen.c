/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:37:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/30 00:47:51 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	cal_dda(t_info *info)
{
	print_floor_ceilling(info);
	//벽 캐스팅
	int x = 0;
	int i;
	t_wall wall;
	while (x < info->width)
	{
		wall.cameraX = 2 * x / (double)info->width - 1; //카메라 평면의 위치 값
		wall.rayDirX = info->dirX + info->planeX * wall.cameraX;//ray 의 방향 계산
		wall.rayDirY = info->dirY + info->planeY * wall.cameraX;
		wall.mapX = (int)info->posX;
		wall.mapY = (int)info->posY; //현재위치 자연수
		// 다음 x면~ 바로 다음 x면까지 광선의 이동거리 1이 들어가는 이유는 비율을 알기위한 것으로 어떤 값이 들어가도 상관 없다
		wall.deltaDistX = fabs(1 / wall.rayDirX);
		wall.deltaDistY = fabs(1 / wall.rayDirY);

		wall.hit = 0; // 벽에 부딛혔는지
		// 4분면 방향 설정과 현재위치에서 다음 좌표까지의 거리(sideDist) 계산
		if (wall.rayDirX < 0)
		{
			wall.stepX = -1;
			wall.sideDistX = (info->posX - wall.mapX) * wall.deltaDistX;
		}
		else
		{
			wall.stepX = 1;
			wall.sideDistX = (wall.mapX + 1.0 - info->posX) * wall.deltaDistX;
		}
		if (wall.rayDirY < 0)
		{
			wall.stepY = -1;
			wall.sideDistY = (info->posY - wall.mapY) * wall.deltaDistY;
		}
		else
		{
			wall.stepY = 1;
			wall.sideDistY = (wall.mapY + 1.0 - info->posY) * wall.deltaDistY;
		}
		//	sideDistX 거리 비교해서 어떤 X,Y 중 먼저 부딪치는 벽면을 카운트 하여 1칸씩 나아간다
		while (!wall.hit)
		{
			if (wall.sideDistX < wall.sideDistY)
			{
				wall.sideDistX += wall.deltaDistX;
				wall.mapX += wall.stepX;
				wall.side = 0;
			}
			else
			{
				wall.sideDistY += wall.deltaDistY;
				wall.mapY += wall.stepY;
				wall.side = 1;
			}
			if (info->config->worldMap[wall.mapX][wall.mapY] > 0)
				wall.hit = 1;
		}
		/*
		 최종적으로 벽을 만났을때 플레이어 기준이 아닌 카메라 기준에서 벽까지의 "수직" 거리를 측정
		 플레이어 기준으로 벽의 거리를 측정할 시에 벽의 높이가 일정하게 보이고 둥글게 보이는 현상 나타남 
		 (1 - stepX) / 2) 은 방향에 따른 + 1을 해주는 이유
		*/
		if (wall.side == 0)
		{
			wall.perpWallDist = (wall.mapX - info->posX + (1 - wall.stepX) / 2) / wall.rayDirX;
			if (wall.stepX < 0)
				wall.textNum = 4;
			else
				wall.textNum = 5;
		}
		else
		{
			wall.perpWallDist = (wall.mapY - info->posY + (1 - wall.stepY) / 2) / wall.rayDirY;
			if (wall.stepY < 0)
				wall.textNum = 6;
			else
				wall.textNum = 7;
		}
		
		//화면 길이에 따른 비율을 설정한뒤 길이의 절반을 기준으로 찍어낼 픽셀의 start 와 end를 구한다.
		// 만약 0 보다 작거나 info->height 보다 크다면 기본값 수정해준다.
		wall.lineHeight = (int)(info->height / wall.perpWallDist);

		wall.drawStart = -wall.lineHeight / 2 + info->height / 2;
		if (wall.drawStart < 0)
			wall.drawStart = 0;
		wall.drawEnd = wall.lineHeight / 2 + info->height / 2;
		if (wall.drawEnd >= info->height)
			wall.drawEnd = info->height - 1;
		if (wall.side == 0)
			wall.wallX = info->posY + wall.perpWallDist * wall.rayDirY;
		else
			wall.wallX = info->posX + wall.perpWallDist * wall.rayDirX;
		wall.wallX -= floor(wall.wallX);

		wall.texX = (int)(wall.wallX * (double)textWidth);
		if (wall.side == 0 && wall.rayDirX > 0)
			wall.texX = textWidth - wall.texX - 1;
		if (wall.side == 1 && wall.rayDirY < 0)
			wall.texX = textWidth - wall.texX - 1;
		wall.step = 1.0 * textHeight / wall.lineHeight;
		wall.texPos = (wall.drawStart - info->height / 2 + wall.lineHeight / 2) * wall.step;
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

void	set_floor_val(t_floor *floor, t_info *info)
{
	floor->rayDirX0 = info->dirX - info->planeX;
	floor->rayDirY0 = info->dirY - info->planeY;
	floor->rayDirX1 = info->dirX + info->planeX;
	floor->rayDirY1 = info->dirY + info->planeY;
	floor->p = floor->y - info->height / 2;
	floor->posZ = 0.5 * info->height;
	floor->rowDistance = floor->posZ / floor->p;
	floor->floorStepX = floor->rowDistance * (floor->rayDirX1 - floor->rayDirX0) / info->width;
	floor->floorStepY = floor->rowDistance * (floor->rayDirY1 - floor->rayDirY0) / info->width;
	floor->floorX = info->posX + floor->rowDistance * floor->rayDirX0;
	floor->floorY = info->posY + floor->rowDistance * floor->rayDirY0;
}

void	print_floor_ceilling(t_info *info)
{
	t_floor floor;

	floor.y = info->height / 2 + 1;
	while (floor.y < info->height)
	{
		set_floor_val(&floor, info);
		floor.x = 0;
		while (floor.x < info->width)
		{
			floor.cellX = (int)floor.floorX;
			floor.cellY = (int)floor.floorY;
			floor.tx = (int)(textWidth * (floor.floorX - floor.cellX)) & (textWidth - 1);
			floor.ty = (int)(textHeight * (floor.floorY - floor.cellY)) & (textHeight - 1);
			floor.floorX += floor.floorStepX;
			floor.floorY += floor.floorStepY;
			floor.color = info->texture[9][textWidth * floor.ty + floor.tx];
			floor.color = (floor.color >> 1) & 8355711;
			info->buf[floor.y][floor.x] = floor.color;
			floor.color = info->texture[8][textWidth * floor.ty + floor.tx];
			floor.color = (floor.color >> 1) & 8355711;
			info->buf[info->height - floor.y - 1][floor.x] = floor.color;
			floor.x++;
		}
		floor.y++;
	}
}
