/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:02:46 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 00:28:15 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	print_sprite(t_config *config, t_info *info)
// {
// 	for (int i = 0; i < numSprites; i++)
// 	{
// 		spriteOrder[i] = i;
// 		spriteDistance[i] = ((info->posX - sprite[i].x) * (info->posX - sprite[i].x)
// 		+ (info->posY - sprite[i].y) *
// 		(info->posY - sprite[i].y));
// 	}

// 	sortSprites(spriteOrder, spriteDistance, numSprites);

// 	for(int i = 0; i < numSprites; i++)
// 	{
// 		double spriteX = sprite[spriteOrder[i]].x - info->posX;
// 		double spriteY = sprite[spriteOrder[i]].y - info->posY;

// 		double invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY);
		
// 		double transformX = invDet * (info->dirY * spriteX - info->dirX * spriteY);
// 		double transformY = invDet * (-info->planeY * spriteX + info->planeX * spriteY);

// 		int spriteScreenX = (int)((info->width / 2) * (1 + transformX / transformY));
// 		#define uDiv 1
// 		#define vDiv 1
// 		#define vMove 0.0
// 		int vMoveScreen = (int)(vMove / transformY);

// 		//sprite 높이계산
// 		int spriteHeight = (int)fabs((info->height / transformY) / vDiv);
// 		int drawStartY = -spriteHeight / 2 + info->height / 2 + vMoveScreen;
// 		if (drawStartY < 0)
// 			drawStartY = 0;
// 		int drawEndY = spriteHeight / 2 + info->height / 2 + vMoveScreen;
// 		if (drawEndY >= info->height)
// 			drawEndY = info->height - 1;
// 		//sprite 너비계산
// 		int spriteWidth = (int)fabs((info->height / transformY) / uDiv);
// 		int drawStartX = -spriteWidth / 2 + spriteScreenX;
// 		if (drawStartX < 0) drawStartX = 0;
// 		int drawEndX = spriteWidth / 2 + spriteScreenX;
// 		if (drawEndX >= info->width) drawEndX = info->width - 1;

// 		for (int stripe = drawStartX; stripe < drawEndX; stripe++)
// 		{
// 			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * textWidth / spriteWidth) / 256);
// 			if (transformY > 0 && stripe > 0 && stripe < info->width && transformY < info->zBuffer[stripe])
// 			for (int y = drawStartY; y < drawEndY; y++)
// 			{
// 				int d = (y-vMoveScreen) * 256 - info->height * 128 + spriteHeight * 128;
// 				int texY = ((d * textHeight) / spriteHeight) / 256;
// 				int color = info->texture[sprite[spriteOrder[i]].texture][textWidth * texY + texX];
// 				if ((color & 0x00FFFFFF) != 0)
// 					info->buf[y][stripe] = color;
// 			}
// 		}
// 	}
// }