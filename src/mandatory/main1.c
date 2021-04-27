/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:17:08 by hyospark          #+#    #+#             */
/*   Updated: 2021/04/27 21:54:44 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char *argv[])
{
	int		fd;
	int 	check;
	char	*buf;
	t_config config;

	if (check_arg(argc, argv))
		return (0);
	fd = open(argv[1], O_RDWR);
	while ((check = get_next_line(fd, &buf)) > 0)
	{
		check_map(buf, &config);
		free(buf);
	}
	return 0;
}