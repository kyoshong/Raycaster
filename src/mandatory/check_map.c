/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:01:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/05/03 21:48:34 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		check_val(t_config *config)
{
	int i;
	
	i = 0;
	while (config->check_val[i])
	{
		if (!config->check_val[i])
			return (0);
		i++;
	}
	return (NOT_ENOUGH_CONFIG);
}

int		map_avail(t_map *map)
{
	t_map *tem;
	int i;
	int count;

	count = 0;
	tem = map;
	while (tem->next_map_line != NULL)
	{
		i = 0;
		while (tem->map_line[i])
		{
			if (ft_strchr("012N ",tem->map_line[i]))
			{
				if (tem->map_line[i] == 'N')
					count++;
			}
			else
				return (WRONG_MAP_CAHR);
			i++;
		}
		tem = map->next_map_line;
	}
	if (count != 1)
		return (MAP_POS_ERROR);
	return (SUCCESS);
}

int		check_map(char *line, t_config *config)
{
	int error;
	
	if (line[0] == 'R')
	{
		error = check_screen(line, &config, 1);
	}
	else if (ft_strchr("NSWE", line[0]))
	{
		error = check_path(line, &config);
	}
	else if (ft_strchr("FC", line[0]))
	{
		error = check_rgb(line, &config);
	}
	else if (line == '\n' || line == '\0')
	{
		error = SUCCESS;
	}
	else if (!check_map_val(line, &config))
	{
		error = SUCCESS;
	}
	else
		error = MAP_FILE_ERROR;
	return (error);
}
