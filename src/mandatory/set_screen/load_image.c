/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:40:11 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/10 20:09:16 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	convert_image(t_info *info, int *texture, char *path, t_img *img)
{
	char	*tem;

	tem = ft_substr(path, ft_strlen(path) - 4, 4);
	if (!ft_strncmp(tem, ".xpm", 4))
		img->img = mlx_xpm_file_to_image(info->mlx, path, &img->width, &img->height);
	else if (!ft_strncmp(tem, ".png", 4))
		img->img = mlx_png_file_to_image(info->mlx, path, &img->width, &img->height);
	else
		cub3d_error_exit(info, "IMG_ERROR");
	if (img->img == NULL)
		cub3d_error_exit(info, "IMG_ERROR");
	img->data = (int *)mlx_get_data_addr(img->img,&img->bpp, &img->size_l, &img->endian);
	if (img->data == NULL)
	{
		mlx_destroy_image(info->mlx, img->img);
		cub3d_error_exit(info, "IMG_ERROR");
	}
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
				texture[img->width * y + x] = img->data[img->width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
	free(tem);
}

void	load_texture(t_info *info)
{
	t_img	img;

	convert_image(info, info->texture[0], info->config->north, &img);
	convert_image(info, info->texture[1], info->config->south, &img);
	convert_image(info, info->texture[2], info->config->west, &img);
	convert_image(info, info->texture[3], info->config->east, &img);
}