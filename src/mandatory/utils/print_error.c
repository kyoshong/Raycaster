/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:02:52 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/10 23:12:35 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	buf_error_exit(char *str, char *buf, t_config *config)
{
	printf("ERROR\n%s", str);
	free(buf);
	config_path_free(config);
	free(config);
	exit(1);
}

void	error_exit(char *str)
{
	printf("ERROR\n%s", str);
	exit(1);
}

void	map_avail_error_exit(t_config *config, char *str)
{
	printf("ERROR\n%s", str);
	config_path_free(config);
	free(config);
	exit(1);
}


void	cub3d_error_exit(t_info *info, char *str)
{
	printf("ERROR\n%s", str);
	cub3d_free_all(info);
	config_path_free(info->config);
	free(info->config);
	exit(1);
}

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
	// system("leaks cub3D > ../leaks_result_temp;cat ../leaks_result_temp | grep leaked && rm -rf ../leaks_result_temp");
	exit(0);
}
