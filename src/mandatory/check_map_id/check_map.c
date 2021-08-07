/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:31:03 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/08 00:34:11 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_val(t_config *config)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (config->check_val[i] != 1)
			return (1);
		i++;
	}
	return (0);
}

void	get_map(char *line, t_config *config)
{
	t_map *map;

	map = ft_new_map(line);
	if (map == NULL)
		buf_error_exit("NEW_MAP_ERROR", line, config);
	ft_lstadd_back_map(&(config->map), map);
}

int		check_map_val(char *line, t_config *config)
{
	int i;

	if (check_val(config))
		buf_error_exit("NOT_ENOUGH_CONFIG", line, config);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1' || line[ft_strlen(line) - 1] != '1')
		buf_error_exit("INVAILED_MAP", line, config);
	get_map(line, config);
	return (1);
}
