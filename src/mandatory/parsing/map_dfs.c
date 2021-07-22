/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:37:09 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/20 13:01:00 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		dfs_map(t_config *t, int **map, int x, int y)
{
	if (x == 0 || x == t->mapHeight - 1 || y == 0 | y == t->mapWidth - 1)
		free_error_exit(t->map, "INVAILED_MAP");
	if (map[x][y] == 0 || map[x][y] == 3)
		map[x][y] = -2;
	if (map[x][y] == -1)
		free_error_exit(t->map, "INVAILED_MAP");
	if (x < t->mapHeight - 1 && map[x + 1][y] == 0)
		dfs_map(t, map, x + 1, y);
	if (x > 0 && map[x - 1][y] == 0)
		dfs_map(t, map, x - 1, y);
	if (y < t->mapWidth - 1 && map[x][y + 1] == 0)
		dfs_map(t, map, x, y + 1);
	if (y > 0 && map[x][y - 1] == 0)
		dfs_map(t, map, x, y - 1);
}

void	dfs_map_check(t_config *config, int player_x, int player_y)
{
	int **map;

	map = config->worldMap;
	dfs_map(config, map, config->player.x, config->player.y);
}
