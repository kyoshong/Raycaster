/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:37:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 20:59:26 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cal_dda(t_info *info)
{
	//벽 캐스팅
	int x = 0;
	while (x < info->width)
	{
		double cameraX = 2 * x / (double)info->width - 1; //카메라 평면의 위치 값
		double rayDirX = info->dirX + info->planeX * cameraX;//ray 의 방향 계산
		double rayDirY = info->dirY + info->planeY * cameraX;
		int mapX = (int)info->posX;
		int mapY = (int)info->posY; //현재위치 자연수 저장

		// 다음 x면~ 바로 다음 x면까지 광선의 이동거리 1이 들어가는 이유는 비율을 알기위한 것으로 어떤 값이 들어가도 상관 없다
		double sideDistX; //시작점 ~ 첫번째 x를 만나는 점
		double sideDistY;
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0; // 벽에 부딛혔는지
		int side; // 벽 사이드인지
		// 4분면 방향 설정과 현재위치에서 다음 좌표까지의 거리(sideDist) 계산
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		//	sideDistX 거리 비교해서 어떤 X,Y 중 먼저 부딪치는 벽면을 카운트 하여 1칸씩 나아간다
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (info->config->worldMap[mapX][mapY] < -1)
				hit = 1;
		}
		/*
		 최종적으로 벽을 만났을때 플레이어 기준이 아닌 카메라 기준에서 벽까지의 "수직" 거리를 측정
		 플레이어 기준으로 벽의 거리를 측정할 시에 벽의 높이가 일정하게 보이고 둥글게 보이는 현상 나타남 
		 (1 - stepX) / 2) 은 방향에 따른 + 1을 해주는 이유
		*/
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		//화면 길이에 따른 비율을 설정한뒤 길이의 절반을 기준으로 찍어낼 픽셀의 start 와 end를 구한다.
		// 만약 0 보다 작거나 info->height 보다 크다면 기본값 수정해준다.
		int lineHeight = (int)(info->height / perpWallDist);

		int drawStart = -lineHeight / 2 + info->height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + info->height / 2;
		if (drawEnd >= info->height)
			drawEnd = info->height - 1;
		int textNum = info->config->worldMap[mapX][mapY] - 1;

		double wallX;
		if (side == 0)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)textWidth);
		if (side == 0 && rayDirX > 0)
			texX = textWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = textWidth - texX - 1;
		double step = 1.0 * textHeight / lineHeight;
		double texPos = (drawStart - info->height / 2 + lineHeight / 2) * step;
		for (int i = drawStart; i < drawEnd; i++)
		{
			int texY = (int)texPos & (textHeight - 1);
			texPos += step;
			int color = info->texture[textNum][textHeight * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[i][x] = color;
		}
		info->zBuffer[x] = perpWallDist;
		x++;
	}
}

void	print_floor_ceilling(t_info *info)
{
	int x;
	int y;

	y = info->height / 2 + 1;
	while (y < info->height)
	{
		float rayDirX0 = info->dirX - info->planeX;
		float rayDirY0 = info->dirY - info->planeY;
		float rayDirX1 = info->dirX + info->planeX;
		float rayDirY1 = info->dirY + info->planeY;

		int p = y - info->height / 2;
		float posZ = 0.5 * info->height;

		float rowDistance = posZ / p;
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / info->width;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / info->width;

		float floorX = info->posX + rowDistance * rayDirX0;
		float floorY = info->posY + rowDistance * rayDirY0;
		x = 0;
		while (x < info->width)
		{
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			int tx = (int)(textWidth * (floorX - cellX)) & (textWidth - 1);
			int ty = (int)(textHeight * (floorY - cellY)) & (textHeight - 1);

			floorX += floorStepX;
			floorY += floorStepY;
			int	checkPattern = (int)(cellX + cellY) & 1;
			int floorTexture;
			if (checkPattern == 0)
				floorTexture = 3;
			else 
				floorTexture = 4;
			int ceilingTexture = 6;

			int color;
			// floor
			color = info->texture[floorTexture][textWidth * ty + tx];
			color = (color >> 1) & 8355711; // 점점 어둡게

			info->buf[y][x] = color;
			//ceiling
			color = info->texture[ceilingTexture][textWidth * ty + tx];
			color = (color >> 1) & 8355711;

			info->buf[info->height - y - 1][x] = color;
			x++;
		}
		y++;
	}
}

// void	print_wall(t_info *info)
// {

// }