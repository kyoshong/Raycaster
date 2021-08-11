/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:21:48 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 03:41:03 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	key_left(t_info *info)
{
	if (info->key_a)
	{
		if (!info->config->worldMap \
		[(int)(info->posX - info->planeX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->planeX * info->moveSpeed;
		if (!info->config->worldMap \
		[(int)(info->posX)][(int)(info->posY - info->planeY * info->moveSpeed)])
			info->posY -= info->planeY * info->moveSpeed;
	}
}

void	key_right(t_info *info)
{
	if (info->key_d)
	{
		if (!info->config->worldMap \
		[(int)(info->posX + info->planeX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->planeX * info->moveSpeed;
		if (!info->config->worldMap \
		[(int)(info->posX)][(int)(info->posY + info->planeY * info->moveSpeed)])
			info->posY += info->planeY * info->moveSpeed;
	}
}

void	key_forword(t_info *info)
{
	if (info->key_w)
	{
		if (!info->config->worldMap \
		[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!info->config->worldMap \
		[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	if (info->key_s)
	{
		if (!info->config->worldMap \
		[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!info->config->worldMap \
		[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
}

void	key_update(t_info *info)
{
	key_right_rotate(info);
	key_left_rotate(info);
	key_right(info);
	key_left(info);
	key_forword(info);
}
