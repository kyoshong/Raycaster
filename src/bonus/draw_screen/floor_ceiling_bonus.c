/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:42:49 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 03:41:29 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	print_floor_ceilling(t_info *info)
{
	t_horizon	horizon;

	horizon.y = info->height / 2 + 1;
	horizon.ceilingcolor = info->config->ceiling;
	horizon.floorcolor = info->config->floor;
	while (horizon.y < info->height)
	{
		horizon.x = 0;
		while (horizon.x < info->width)
		{
			info->buf[horizon.y][horizon.x] = horizon.ceilingcolor;
			info->buf[info->height - horizon.y - 1][horizon.x] \
			= horizon.floorcolor;
			horizon.x++;
		}
		horizon.y++;
	}
}
