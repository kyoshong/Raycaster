/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:42:49 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/10 20:08:38 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_floor_ceilling(t_info *info)
{
	t_horizon horizon;

	horizon.y = info->height / 2 + 1;
	horizon.ceilingcolor = info->config->ceiling;
	// printf("%d\n",info->config->ceiling);
	// printf("%d\n",info->config->floor);
	horizon.floorcolor = info->config->floor;
	while (horizon.y < info->height)
	{
		horizon.x = 0;
		while (horizon.x < info->width)
		{
			info->buf[horizon.y][horizon.x] = horizon.ceilingcolor;
			info->buf[info->height - horizon.y - 1][horizon.x] = horizon.floorcolor;
			horizon.x++;
									//horizon.color = (horizon.color >> 1) & 8355711;

		}
		// horizon.ceilingcolor = horizon.ceilingcolor + 128;
		// horizon.floorcolor = horizon.floorcolor + 128;
		horizon.y++;
	}
}
