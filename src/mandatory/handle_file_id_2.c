
#include "cub3d.h"

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

void	check_rgb(char *line, t_config *config)
{
	char	*tem;
	int		i;

	while (!ft_isdigit(line[i]))
		i++;
	if ((tem = ft_substr(line, i, ft_strlen(line))) == NULL)
		buf_free_error_exit("RGB_VALUE_ERROR", &line);
	i = 0;
	if (line[0] == 'F')
	{
		if ((config->floor = ft_split_atoi(tem, ',')) == NULL)
			buf_free_error_exit("RGB_VALUE_ERROR", &line);
		config->check_val[7] = 1;
	}
	else if (line[0] == 'C')
	{
		if((config->ceiling = ft_split_atoi(tem, ',')) == NULL)
			buf_free_error_exit("RGB_VALUE_ERROR", &line);
		config->check_val[8] = 1;
	}
}
