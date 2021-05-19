/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:02:52 by hyospark          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/18 20:28:22 by hyospark         ###   ########.fr       */
=======
/*   Updated: 2021/05/07 03:01:15 by hyospark         ###   ########.fr       */
>>>>>>> 8c5d03cbc10d46b391996af9be5dcc938d6a15e4
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *str)
{
	printf("ERROR\n%s", str);
	exit(1);
}

void	free_error_exit(t_map *map, char *str)
{
	ft_lstclear_map(map);
	printf("ERROR\n%s", str);
	exit(1);
}

void	map_error_exit(char *str, t_map **map)
{
	ft_lstclear_map(map);
	printf("ERROR\n%d", str);
	exit(1);
}