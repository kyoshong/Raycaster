/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_avail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:01:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 16:45:41 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map_char_sprite(t_config *config, int max, int count)
{
	t_map *tem;
	int i;

	tem = config->map;
	while (1)
	{
		i = 0;
		while (tem->map_line[i] != '\0')
		{
			printf("%c", tem->map_line[i]);
			if (tem->map_line[i] == 'N')
				count++;
			else if (ft_strchr("012 ",tem->map_line[i]) == NULL)
				free_map_error_exit(config->map, "WRONG_MAP_CAHR");
			i++;
			if (max < i)
				max = i;
		}
		printf("\n");
		if (tem->next_map_line == NULL)
			break ;
		tem = tem->next_map_line;
		config->mapHeight++;
	}
	if (count != 1)
		free_map_error_exit(config->map, "MAP_POS_ERROR");
	return (max);
}

int		check_map_char(t_config *config, int max, int count)
{
	t_map *tem;
	int i;

	tem = config->map;
	while (1)
	{
		i = 0;
		while (tem->map_line[i])
		{
			if (tem->map_line[i] == 'N')
					count++;
			else if (!ft_strchr("01 ",tem->map_line[i]))
				free_map_error_exit(config->map, "WRONG_MAP_CAHR");
			i++;
			if (max < i)
				max = i;
		}
		if (tem->next_map_line == NULL)
			break ;
		tem = tem->next_map_line;
		config->mapHeight++;
	}
	if (count != 1)
		free_map_error_exit(config->map, "MAP_POS_ERROR");
	return (max);
}

int		*make_map_arr(int s)
{
	int *arr;
	int i;

	if (!(arr = (int *)malloc(sizeof(int) * s)))
		return NULL;
	i = 0;
	while (i < s)
	{
		arr[i] = -1;
		i++;
	}
	return (arr);
}

void	make_worldMap(t_config *config, int i, int h, int w)
{
	int		**arr;
	t_map	*tem;

	if (!(arr = (int**)malloc(sizeof(int *) * config->mapHeight)))
		return free_map_error_exit(config->map, "ARRAY_MALLOC_ERROR");
	while (i <= config->mapHeight)
	{
		arr[i] = make_map_arr(config->mapWidth);
		i++;
	}
	tem = config->map;
	while (1)
	{
		i = 0;
		w = 0;
		while (tem->map_line[i] != '\0')
		{
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
			w++;
		}
		if (tem->next_map_line == NULL)
			break ;
		tem = tem->next_map_line;
		h++;
	}
	config->worldMap = arr;
}

void	map_avail(t_config *config)
{
	if (config->sprite_ver)
		config->mapWidth = check_map_char_sprite(config, 0, 0);
	else
		config->mapWidth = check_map_char(config, 0, 0);
	make_worldMap(config, 0, 0, 0);
	dfs_map_check(config);
}
