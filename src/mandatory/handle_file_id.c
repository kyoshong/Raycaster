
#include "cub3d.h"

void	check_screen(char *line, t_config *config, int i)
{
	int		width;
	int		height;
	
	width = 0;
	height = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		width = (width * 10) + ((line[i++] - '0'));
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		height = (height * 10) + ((line[i++] - '0'));
	if (height > 0 && width > 0)
	{
		config->width = width;
		config->height = height;
		config->check_val[0] = 1;
		config->check_val[1] = 1;
	}
	buf_free_error_exit("SCREEN_VALUE_ERROR", line);
}


void	check_path(char *line, t_config *config)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (NULL == (config->north = (re_path(line, 2))))
			error_exit("PATH_NO_ERROR");
		config->check_val[2] = 1;
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		if (NULL == (config->south = (re_path(line, 2))))
			error_exit("PATH_SO_ERROR");
		config->check_val[3] = 1;
	}
	else if (!ft_strncmp(line, "S ", 2))
	{
		if (NULL == (config->sprite = (re_path(line, 2))))
			error_exit("PATH_S_ERROR");
		config->check_val[6] = 1;
	}
}

void	check_path2(char *line, t_config *config)
{
	if (ft_strncmp(line, "WE", 2))
	{
		if (NULL == (config->west = (re_path(line, 2))))
			error_exit("PATH_WE_ERROR");
		config->check_val[4] = 1;
	}
	else if (ft_strncmp(line, "EA", 2))
	{
		if (NULL == (config->east = (re_path(line, 2))))
			error_exit("PATH_EA_ERROR");
		config->check_val[5] = 1;
	}
}

int	check_map_id(char *line, t_config *config)
{
	int i;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (line[i] == 'R')
		check_screen(line, &config, i + 1);
	else if (ft_strchr("NSWE", line[i]))
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
	return (0);
}
