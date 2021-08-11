/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:36:34 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 16:00:15 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_arr(int **arr, int i)
{
	while (i >= 0)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i--;
	}
	free(arr);
}

void	free_worldMap(t_config *config)
{
	int	i;

	i = 0;
	if (config->worldMap != NULL)
	{
		while (i <= config->mapHeight)
		{
			if (config->worldMap[i] != NULL)
				free(config->worldMap[i]);
			i++;
		}
		free(config->worldMap);
	}
}

void	config_path_free(t_config *config)
{
	if (config->check_val[0])
		free(config->north);
	if (config->check_val[1])
		free(config->south);
	if (config->check_val[2])
		free(config->west);
	if (config->check_val[3])
		free(config->east);
	if (config->sprite_ver)
		free(config->sprite);
	if (config->map != NULL)
		ft_lstclear_map(config->map);
	free_worldMap(config);
}

void	cub3d_free_all(t_info *info)
{
	if (info->buf != NULL)
		free_arr(info->buf, info->height - 1);
	if (info->texture != NULL)
		free_arr(info->texture, PICS_NUM - 1);
}
