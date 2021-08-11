/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:06:20 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 15:57:37 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_left_rotate(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	if (info->key_AR_L == 1)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - \
		info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + \
		info->dirY * cos(info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - \
		info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + \
		info->planeY * cos(info->rotSpeed);
	}
}

void	key_right_rotate(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	if (info->key_AR_R == 1)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - \
		info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + \
		info->dirY * cos(-info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - \
		info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + \
		info->planeY * cos(-info->rotSpeed);
	}
}
