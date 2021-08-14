/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:42:49 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/14 17:46:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			info->buf[horizon.y][horizon.x] = horizon.floorcolor;
			info->buf[info->height - horizon.y - 1][horizon.x] \
			= horizon.ceilingcolor;
			horizon.x++;
		}
		horizon.y++;
	}
}
