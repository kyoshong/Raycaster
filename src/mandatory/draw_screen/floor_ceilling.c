/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:42:49 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/03 17:54:25 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_floor_ceilling(t_info *info)
{
	t_horizon horizon;

	horizon.y = info->height / 2 + 1;
	while (horizon.y < info->height)
	{
		horizon.x = 0;
		while (horizon.x < info->width)
		{
			horizon.color = info->config->ceiling;
			//horizon.color = (horizon.color >> 1) & 8355711;
			info->buf[horizon.y][horizon.x] = horizon.color;
			horizon.color = info->config->floor;
			//horizon.color = (horizon.color >> 1) & 8355711;
			info->buf[info->height - horizon.y - 1][horizon.x] = horizon.color;
			horizon.x++;
		}
		horizon.y++;
	}
}
