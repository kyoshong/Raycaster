/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:28:46 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 15:25:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_position(t_config *config, int h, int w, int **arr)
{
	config->player.x = h;
	config->player.y = w;
	arr[h][w] = 0;
}

void	set_worldMap(t_config *config, int h, int w, int **arr)
{
	int		i;
	t_map	*tem;

	tem = config->map;
	while (1)
	{
		i = 0;
		w = 0;
		while (tem->map_line[i] && (w < config->mapWidth + 1))
		{
			if (tem->map_line[i] == '0' || tem->map_line[i] == '1' \
			|| tem->map_line[i] == '2')
				arr[h][w] = tem->map_line[i] - '0';
			else if (tem->map_line[i] == 'N')
				set_position(config, h, w, arr);
			i++;
			w++;
		}
		if (tem->next_map_line == NULL)
			break ;
		tem = tem->next_map_line;
		h++;
	}
}

void	make_worldMap(t_config *config)
{
	int		**arr;
	int		i;

	arr = (int **)malloc(sizeof(int *) * (config->mapHeight + 1));
	if (!arr)
		return (map_avail_error_exit(config, "ARRAY_MALLOC_ERROR"));
	i = 0;
	while (i <= config->mapHeight)
	{
		arr[i] = make_map_arr(config->mapWidth);
		if (arr[i] == NULL)
		{
			free_arr(arr, i - 1);
			map_avail_error_exit(config, "ARRAY_MALLOC_ERROR");
		}
		i++;
	}
	set_worldMap(config, 0, 0, arr);
	config->worldMap = arr;
}
