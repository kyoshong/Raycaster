/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:08 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 01:39:16 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arg(int argc, char **argv)
{
	int a;

	if (argc < 2)
		error_exit("TOO_FEW_ARG");
	if (argc > 3)
		error_exit("TOO_MANY_ARG");
	a = ft_strlen(argv[1]);
	if (argc == 2 && ft_strncmp(ft_substr(argv[1], a - 4, 4), ".cub", 4) != 0)
		error_exit("FILE_NAME_ERROR");
}

t_config	*init_config()
{
	t_config *config;
	int i;

	i = 0;
	config = (t_config *)malloc(sizeof(*config));
	if (config == NULL)
		error_exit("malloc_config_error");
	
	while (i < 6)
		config->check_val[i++] = 0;
	config->sprite_ver = 0;
	return (config);
}

int		main(int argc, char *argv[])
{
	int			fd;
	int			check;
	char		*buf;
	t_config	*config;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDWR);
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
	printf("SUCCESS");
	//start_cub3d(config);
	return (0);
}
