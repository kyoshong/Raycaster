/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:01:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/04/28 20:41:01 by hyospark         ###   ########.fr       */
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

int		check_map_val(char *line, t_config *config)
{
	int i;
	
	if (check_val(&config) > 0)
		return (NOT_ENOUGH_CONFIG);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		config->
		while (ft_isdigit(line[i]))
		{
			
			i++;
		}
		i = 0;
		
	}
	else

	
	
	
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
	else if ()
	{
		
	}
	else
		error = MAP_FILE_ERROR;
	return (error);
}
