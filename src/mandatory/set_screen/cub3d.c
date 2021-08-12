/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:37 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 22:34:09 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main_loop(t_info *info)
{
	dda(info, 0, 0);
	mini_map(info);
	draw(info);
	key_update(info);
	return (0);
}

void	start_cub3d(t_config *config)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(*info));
	if (info == NULL)
		map_avail_error_exit(config, "MLX_INIT_ERROR");
	set_config(config, info);
	set_buf(info);
	set_texture(info, 0, 0);
	load_texture(info);
	info->win = mlx_new_window(info->mlx, info->width, info->height, "cub3D");
		printf("info->win : %p\n",info->win);
	if (info->win == NULL)
		cub3d_error_exit(info, "NEW_WINDOW_ERROR");
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	printf("info->img.img : %p\n",info->img.img);
	if (info->img.img == NULL)
		cub3d_error_exit(info, "NEW_IMAGE_ERROR");
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, \
	&info->img.size_l, &info->img.endian);
	if (info->img.data == NULL)
		cub3d_error_exit(info, "GET_DATA_ADDR_ERROR");
	mlx_hook_ready(info);
}
