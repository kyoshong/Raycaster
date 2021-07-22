
#include "cub3d.h"

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

int		get_map(char *line, t_config *config)
{
	t_map *map;

	map = ft_new_map(line);
	if (map == NULL)
		free_all_error_exit(config->map, "NEW_MAP_ERROR", line);
	ft_lstadd_back(&(config->map->map_line), &map);
	return (0);
}

int		check_map_val(char *line, t_config *config)
{
	int i;

	if (check_val(&config))
		free_all_error_exit(config->map, "NOT_ENOUGH_CONFIG", line);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 1 && get_map(line, &config))
		return (0);
	else
		free_all_error_exit(config->map,"MAP_ERROR", line);
}
