/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_avail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:01:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/05 03:21:03 by hyospark         ###   ########.fr       */
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
			if (tem->map_line[i] == 'N')
				count++;
			else if (ft_strchr("012 ",tem->map_line[i]) == NULL)
				map_avail_error_exit(config, "WRONG_MAP_CAHR");
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
		map_avail_error_exit(config, "MAP_POS_ERROR");
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
				map_avail_error_exit(config, "WRONG_MAP_CAHR");
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
		map_avail_error_exit(config, "MAP_POS_ERROR");
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

void	map_avail(t_config *config)
{
	if (config->sprite_ver)
		config->mapWidth = check_map_char_sprite(config, 0, 0);
	else
		config->mapWidth = check_map_char(config, 0, 0);
	make_worldMap(config);
	dfs_map_check(config);
}
