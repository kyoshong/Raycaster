/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_avail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:01:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/20 13:00:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_char_sprite(t_map *map, int i, int count)
{
	t_map *tem;
	int max;

	tem = map;
	max = 0;
	while (tem->next_map_line != NULL)
	{
		i = 0;
		while (tem->map_line[i])
		{
			if (tem->map_line[i] == 'N')
					count++;
			if (!ft_strchr("012N ",tem->map_line[i]))
				free_error_exit("WRONG_MAP_CAHR", map);
			i++;
			if (max < i)
				max = i;
		}
		tem = map->next_map_line;
	}
	if (count != 1)
		free_error_exit("MAP_POS_ERROR", map);
	return (max);
}

int		check_map_char(t_map *map, int i, int count)
{
	t_map *tem;
	int max;

	tem = map;
	max = 0;
	while (tem->next_map_line != NULL)
	{
		i = 0;
		while (tem->map_line[i])
		{
			if (tem->map_line[i] == 'N')
					count++;
			if (!ft_strchr("012N ",tem->map_line[i]))
				free_error_exit("WRONG_MAP_CAHR", map);
			i++;
			if (max < i)
				max = i;
		}
		tem = map->next_map_line;
	}
	if (count != 1)
		free_error_exit("MAP_POS_ERROR", map);
	return (max);
}

void	*set_map(void *ptr, int val, size_t s)
{
	while (s != 0)
	{
		*((int *)ptr + s - 1) = val;
		s--;
	}
	return (ptr);
}

void	make_worldMap(t_config *config, int i, int h, int w)
{
	int		arr[config->mapHeight][config->mapWidth];
	t_map	*tem;

	while (i < config->mapHeight)
		set_map(arr[i++], -1, config->mapWidth);
	tem = config->map;
	while (tem->next_map_line != NULL)
	{
		i = 0;
		while (tem->map_line[i])
		{
			w = 0;
			if (tem->map_line[i] == '0' || tem->map_line[i] == '1' \
			|| tem->map_line[i] == '2')
				arr[h][w] = tem->map_line[i] - '0';
			else if (tem->map_line[i] == 'N')
			{
				config->player.x = h;
				config->player.y = w;
				arr[h][w] = 3;
			}
			i++;
		}
		h++;
		tem = config->map->next_map_line;
	}
	config->worldMap = arr;
}


int		map_avail(t_config *config)
{
	if (config->sprite_ver)
		config->mapWidth = check_map_char_sprite(config->map, 0, 0);
	else
		config->mapWidth = check_map_char(config->map, 0, 0);
	config->mapHeight = ft_lstsize_map(config->map);
	make_worldMap(config, 0, 0, 0);
	dfs_map_check(config, config->player.x, config->player.y);
	return (0);
}
