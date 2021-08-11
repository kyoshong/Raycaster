/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:37:09 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 02:53:53 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dfs_map(t_config *config, int **map, int x, int y)
{
	if (x == 0 || x == config->mapHeight || y == 0 | y == config->mapWidth - 1)
		map_avail_error_exit(config, "INVAILED_MAP");
	if (map[x][y] == 0 || map[x][y] == 3)
		map[x][y] = -2;
	if (map[x][y] == -1)
		map_avail_error_exit(config, "INVAILED_MAP");
	if (x < config->mapHeight && map[x + 1][y] > 1)
		dfs_map(config, map, x + 1, y);
	if (x > 0 && map[x - 1][y] != 1)
		dfs_map(config, map, x - 1, y);
	if (y < config->mapWidth - 1 && map[x][y + 1] > 1)
		dfs_map(config, map, x, y + 1);
	if (y > 0 && map[x][y - 1] == 0)
		dfs_map(config, map, x, y - 1);
}

void	dfs_map_check(t_config *config)
{
	int	i;

	dfs_map(config, config->worldMap, config->player.x, config->player.y);
	i = 0;
	free_worldMap(config);
	make_worldMap(config);
}
