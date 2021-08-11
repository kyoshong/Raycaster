/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_avail_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:01:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 03:41:22 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_map_char_val(t_config *config, char c)
{
	char	*val;

	if (config->sprite_ver)
		val = ft_strchr("012 ", c);
	else
		val = ft_strchr("01 ", c);
	if (c == 'N')
		return (1);
	else if (val == NULL)
		map_avail_error_exit(config, "WRONG_MAP_CAHR");
	return (0);
}

int	check_map_char_sprite(t_config *config, int max, int count)
{
	t_map	*tem;
	int		i;

	tem = config->map;
	while (1)
	{
		i = 0;
		while (tem->map_line[i] != '\0')
		{
			count += check_map_char_val(config, tem->map_line[i]);
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

int	check_map_char(t_config *config, int max, int count)
{
	t_map	*tem;
	int		i;

	if (!config->map)
		map_avail_error_exit(config, "NO_MAP_ERROR");
	tem = config->map;
	while (1)
	{
		i = 0;
		while (tem->map_line[i])
		{
			count += check_map_char_val(config, tem->map_line[i]);
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

int	*make_map_arr(int s)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * s);
	if (!arr)
		return (NULL);
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
