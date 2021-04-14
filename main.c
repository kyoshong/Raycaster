
#include "key_h.h"
#include "mlx/mlx.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480
#define X_EVENT_KET_PRESS	2
#define X_EVENT_KEY_EXIT	17

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void	varLine(t_info *info, int x, int y1, int y2, int color)
{
	int y;
	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	calc(t_info *info)
{
	int x;

	x = 0;
	while (x < width)
	{
		double cameraX = 2 * x / (double)width - 1; //카메라 평면의 위치 값
		double rayDirX = info->dirX + (info->planeX * cameraX);//ray 의 방향 계산
		double rayDirY = info->dirY + (info->planeY * cameraX);
		int mapX = (int)info->posX;
		int mapY = (int)info->posY; //현재위치 자연수 저장

// 다음 x면~ 바로 다음 x면까지 광선의 이동거리 1이 들어가는 이유는 비율을 알기위한 것으로 어떤 값이 들어가도 상관 없다
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWAllDist;

		int stepX;
		int stepY;

		int hit = 0; // 벽에 부딛혔는지
		int side; // 벽 사이드인지

		double sideDistX; //시작점 ~ 첫번째 x를 만나는 점
		double sideDistY;
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
			if(sideDistX < sideDistY)
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
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		/*
		 최종적으로 벽을 만났을때 플레이어 기준이 아닌 카메라 기준에서 벽까지의 "수직" 거리를 측정
		 플레이어 기준으로 벽의 거리를 측정할 시에 벽의 높이가 일정하게 보이고 둥글게 보이는 현상 나타남 
		 (1 - stepX) / 2) 은 방향에 따른 + 1을 해주는 이유
		*/
		if (side == 0)
			perpWAllDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWAllDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		
		int lineHeight = (int)(height / perpWAllDist);
		int drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;

		int color;
		if (worldMap[mapX][mapY] == 1)
			color = 0xFF0000;
		else if (worldMap[mapX][mapY] == 2)
			color = 0x00FF00;
		else if (worldMap[mapX][mapY] == 3)
			color = 0x0000FF;
		else
			color = 0xFFFF00;
		if (side == 1)
			color = color / 2;

		varLine(info, x, drawStart, drawEnd, color);
		x++;
	}
}
int	main_loop(t_info *info)
{
	calc(info);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);

	return (0);
}
int	key_press(int key, t_info *info)
{
	if(key == K_W)
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if(!worldMap[(int)(info->dirX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == K_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	if (key == K_D)
	{
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_A)
	{
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) - info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

int main(int argc, char const *argv[])
{
	t_info info;
	info.mlx = mlx_init();

	info.posX = 12;
	info.posY = 5;
	info.dirX = -1;
	info.dirY = 0;
	info.planeX = 0;
	info.planeY = 0.66;
	info.moveSpeed = 0.1;
	info.rotSpeed = 0.1;

	info.win = mlx_new_window(info.mlx, width, height, "test");

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KET_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);
	return 0;
}
