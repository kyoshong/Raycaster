/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:37:09 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 17:01:41 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dfs_map(t_config *config, int **map, int x, int y)
{
	if (x == 0 || x == config->mapHeight || y == 0 | y == config->mapWidth - 1)
		free_map_error_exit(config->map, "INVAILED_MAP");
	if (map[x][y] == 0 || map[x][y] == 3)
		map[x][y] = -2;
	if (map[x][y] == -1)
		free_map_error_exit(config->map, "INVAILED_MAP");
	if (x < config->mapHeight && map[x + 1][y] == 0)
		dfs_map(config, map, x + 1, y); 
	if (x > 0 && map[x - 1][y] != 1)
		dfs_map(config, map, x - 1, y);
	if (y < config->mapWidth - 1 && map[x][y + 1] == 0)
		dfs_map(config, map, x, y + 1);
	if (y > 0 && map[x][y - 1] == 0)
		dfs_map(config, map, x, y - 1);
}

void	dfs_map_check(t_config *config)
{
	dfs_map(config, config->worldMap, config->player.x, config->player.y);
	// int a = 0;
	// int b = 0;
	// while (a <= config->mapHeight)
	// {
	// 	b = 0;
	// 	while (b < config->mapWidth)
	// 	{
	// 		printf("%d", config->worldMap[a][b]);
	// 		b++;
	// 	}
	// 	printf("\n");
	// 	a++;
	// }
}
