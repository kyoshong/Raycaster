/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:02:52 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/18 21:23:12 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	buf_free_error_exit(char *str, char *buf)
{
	printf("ERROR\n%s", str);
	free(buf);
}

void	error_exit(char *str)
{
	printf("ERROR\n%s", str);
	exit(1);
}

void	free_all_error_exit(t_map *map, char *str, char *buf)
{
	ft_lstclear_map(map);
	free(buf);
	printf("ERROR\n%s", str);
	exit(1);
}
