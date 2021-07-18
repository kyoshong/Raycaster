/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:08 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/18 17:35:14 by hyospark         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	int			fd;
	int			check;
	char		*buf;
	t_config	config;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		print_error("CAN_NOT_OPEN_FILE");
	check = get_next_line(fd, &buf);
	while (check > 0)
	{
		check = get_next_line(fd, &buf);
		check_map_id(buf, &config);
		free(buf);
	}
	map_avail(&config);
	start_cub3d(&config);
	return (0);
}
