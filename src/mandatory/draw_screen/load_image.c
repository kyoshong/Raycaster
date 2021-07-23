/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:40:11 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 23:01:58 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	x = 0;
	while (x < img->img_height)
	{
		y = 0;
		while (y < img->img_width)
		{
			texture[img->img_width * x + y] = img->data[img->img_width * y + x];
			y++;
		}
		x++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "../textures/eagle.xpm", &img);
	load_image(info, info->texture[1], "../textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "../textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "../textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "../textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "../textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "../textures/wood.xpm", &img);
	load_image(info, info->texture[7], "../textures/colorstone.xpm", &img);
	load_image(info, info->texture[8], "../textures/barrel.xpm", &img);
	load_image(info, info->texture[9], "../textures/pillar.xpm", &img);
	load_image(info, info->texture[10], "../textures/greenlight.xpm", &img);
}