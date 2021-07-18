/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:37:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/18 17:39:32 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_path(char *line, t_config *config)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (NULL == (config->north = (re_path(line, 3))))
			error_exit("PATH_NO_ERROR");
		config->check_val[0] = 1;
	}
	else if (!ft_strncmp(line, "SO ", 3) && config->north != NULL)
	{
		if (NULL == (config->south = (re_path(line, 3))))
			error_exit("PATH_SO_ERROR");
		config->check_val[1] = 1;
	}
	else if (!ft_strncmp(line, "S ", 2))
	{
		if (NULL == (config->sprite = (re_path(line, 2))))
			error_exit("PATH_S_ERROR");
		config->sprite_ver = 1;
	}
}

void	check_path2(char *line, t_config *config)
{
	if (ft_strncmp(line, "WE", 2) && config->south != NULL)
	{
		if (NULL == (config->west = (re_path(line, 2))))
			error_exit("PATH_WE_ERROR");
		config->check_val[2] = 1;
	}
	else if (ft_strncmp(line, "EA", 2) && config->west != NULL)
	{
		if (NULL == (config->east = (re_path(line, 2))))
			error_exit("PATH_EA_ERROR");
		config->check_val[3] = 1;
	}
}

int	check_map_id(char *line, t_config *config)
{
	int i;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (ft_strchr("NS", line[i]))
		check_path(line, &config);
	else if (ft_strchr("WE", line[i]))
		check_path2(line, &config);
	else if (ft_strchr("FC", line[i]))
		check_rgb(line, &config);
	else if (line[i] == '\n' || line[i] == '\0')
		return (0);
	else if (!check_map_val(line, &config))
		return (0);
	else
		error_exit("MAP_FILE_ERROR");
}
