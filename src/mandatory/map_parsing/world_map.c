/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:28:46 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/10 21:57:15 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			{
				config->player.x = h;
				config->player.y = w;
				arr[h][w] = 0;
			}
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
	if (!(arr = (int**)malloc(sizeof(int *) * (config->mapHeight + 1))))
		return map_avail_error_exit(config, "ARRAY_MALLOC_ERROR");
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
	// 		printf("\n");

	// for (int i = 0; i < config->mapHeight + 1; i++)
	// {
	// 	for (int j = 0; j < config->mapWidth; j++)
	// 	{
	// 		printf("%d",arr[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	config->worldMap = arr;

}
