/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:03:04 by hyospark          #+#    #+#             */
/*   Updated: 2021/04/27 23:34:16 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_screen(char *line, t_config *config, int i)
{
	int		width;
	int		height;
	
	width = 0;
	height = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		width = (width * 10) + ((line[i] - '0'));
		i++;
	}
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		height = (height * 10) + ((line[i] - '0'));
		i++;
	}
	if (height > 0 && width > 0)
	{
		config->screen_width = width;
		config->screen_height = height;
		config->check_val[0] = 1;
		config->check_val[1] = 1;
		return (SUCCESS);
	}
	return (SCREEN_VALUE_ERROR);
}

char	*re_path(char *line, int i)
{
	int start;

	while (line[i] == ' ')
		i++;
	start = i;
	while (line[i] != ' ')
		i++;
	if (i > start)
		return (ft_substr(line, start, i));
	return (NULL);
}

int	check_path(char *line, t_config *config)
{
	
	if (!ft_strncmp(line, "NO", 2))
	{
		if (NULL == (config->north = (re_path(line, 2))))
			return (PATH_ERROR);
		config->check_val[2] = 1;
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		if (NULL == (config->south = (re_path(line, 2))))
			return (PATH_ERROR);
		config->check_val[3] = 1;
	}
	else if (ft_strncmp(line, "WE", 2))
	{
		if (NULL == (config->west = (re_path(line, 2))))
			return (PATH_ERROR);
		config->check_val[4] = 1;
	}
	else if (ft_strncmp(line, "EA", 2))
	{
		if (NULL == (config->east = (re_path(line, 2))))
			return (PATH_ERROR);
		config->check_val[5] = 1;
	}
	else if (!ft_strncmp(line, "S ", 2))
	{
		if (NULL == (config->sprite = (re_path(line, 2))))
			return (PATH_ERROR);
		config->check_val[6] = 1;
	}
	return (SUCCESS);
}

int		check_rgb(char *line, t_config *config)
{
	char	*tem;
	int		i;

	while (!ft_isdigit(line[i]))
		i++;
	if ((tem = ft_substr(line, i, ft_strlen(line))) == NULL)
		return (RGB_VALUE_ERROR);
	i = 0;
	if (line[0] == 'F')
	{
		if ((config->floor = ft_split_atoi(tem, ',')) == NULL)
			return (RGB_VALUE_ERROR);
		config->check_val[7] = 1;
	}
	else if (line[0] == 'C')
	{
		if((config->ceiling = ft_split_atoi(tem, ',')) == NULL)
			return (RGB_VALUE_ERROR);
		config->check_val[8] = 1;
	}
	return (SUCCESS);
}

int		check_arg(int argc, char **argv)
{
	int a;
	if (argc < 2)
		return(ARG_ERROR_TOO_FEW);
	if (argc > 3)
		return(ARG_ERROR_TOO_MANY);
	a = ft_strlen(argv[1]);
	if (argc == 2 && ft_strncmp(ft_substr(argv[1], a - 4, 4), ".cub", 4) != 0)
		return(FILE_NAME_ERROR);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0)
		return(SAVE_FLAG_ERROR);
	return (SUCCESS);
}
