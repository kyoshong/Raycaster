/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:58:53 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 19:02:12 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	esc_exit(t_info *info)
{
	printf("ESC_EXIT\n");
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	cub3d_free_all(info);
	config_path_free(info->config);
	free(info->mlx);
	free(info->config);
	exit(0);
}
