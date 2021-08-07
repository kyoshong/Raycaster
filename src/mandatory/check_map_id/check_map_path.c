/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:37:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/08 00:31:31 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_path_ns(char *line, t_config *config)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if ((NULL == (config->north = (re_path(line, 3))) || config->check_val[0]))
			buf_error_exit("PATH_NO_ERROR", line, config);
		config->check_val[0] = 1;
	}
	else if (!ft_strncmp(line, "SO ", 3) && config->north != NULL)
	{
		if ((NULL == (config->south = (re_path(line, 3))) || config->check_val[1]))
			buf_error_exit("PATH_SO_ERROR", line, config);
		config->check_val[1] = 1;
	}
	else if (!ft_strncmp(line, "S ", 2))
	{
		if ((NULL == (config->sprite = re_path(line, 2))) || config->sprite_ver)
			buf_error_exit("PATH_S_ERROR", line, config);
		config->sprite_ver = 1;
	}
}

void	check_path_we(char *line, t_config *config)
{
	if (!ft_strncmp(line, "WE ", 3) && config->south != NULL)
	{
		config->west = re_path(line, 2);
		if (NULL == (config->west) || config->check_val[2])
			buf_error_exit("PATH_WE_ERROR", line, config);
		config->check_val[2] = 1;
	}
	else if (!ft_strncmp(line, "EA ", 3) && config->west != NULL)
	{
		config->east = re_path(line, 2);
		if (NULL == config->east || config->check_val[3])
			buf_error_exit("PATH_EA_ERROR", line, config);
		config->check_val[3] = 1;
	}
}

void	check_map_id(char *line, t_config *config)
{
	int i;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (ft_strchr("NS", line[i]))
		check_path_ns(line, config);
	else if (ft_strchr("WE", line[i]))
		check_path_we(line, config);
	else if (ft_strchr("FC", line[i]))
		check_rgb(line, config, i);
	else if (line[i] == '\n' || line[i] == '\0')
		return ;
	else if (check_map_val(line, config))
		return ;
}
