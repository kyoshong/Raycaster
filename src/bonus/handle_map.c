/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:09 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/18 17:35:10 by hyospark         ###   ########.fr       */
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

int		get_map(char *line, t_config *config)
{
	t_map *map;

	if (!(map = ft_new_map(line)))
		return (NEW_MAP_ERROR);
	ft_lstadd_back(&(config->map->map), &map);
	return (SUCCESS);
}

int		check_map_val(char *line, t_config *config)
{
	int i;

	if (check_val(&config) > 0)
		return (NOT_ENOUGH_CONFIG);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) && get_map(line, &config))
		return (SUCCESS);
	else
		return (MAP_ERROR);
}
