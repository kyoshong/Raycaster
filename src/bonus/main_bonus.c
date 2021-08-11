/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:08 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 04:16:45 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_arg(int argc, char **argv)
{
	int		len;
	char	*path;

	if (argc < 2)
		error_exit("TOO_FEW_ARG");
	if (argc > 3)
		error_exit("TOO_MANY_ARG");
	len = ft_strlen(argv[1]);
	path = ft_substr(argv[1], len - 4, 4);
	if (argc == 2 && ft_strncmp(path, ".cub", 4) != 0)
		error_exit("FILE_NAME_ERROR");
	free(path);
}

t_config	*init_config(void)
{
	t_config	*config;
	int			i;

	i = 0;
	config = (t_config *)malloc(sizeof(*config));
	if (!config)
		error_exit("malloc_config_error");
	while (i < 6)
		config->check_val[i++] = 0;
	config->sprite_ver = 0;
	config->mapHeight = 0;
	config->mapWidth = 0;
	config->ceiling = -1;
	config->floor = -1;
	config->map = NULL;
	return (config);
}

int	main(int argc, char *argv[])
{
	int			fd;
	int			check;
	char		*buf;
	t_config	*config;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("CAN_NOT_OPEN_FILE");
	config = init_config();
	check = 1;
	while (check > 0)
	{
		check = get_next_line(fd, &buf);
		check_map_id(buf, config);
		free(buf);
	}
	map_avail(config);
	start_cub3d(config);
	return (0);
}
