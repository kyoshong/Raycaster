/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:56:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/11 15:53:20 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlx_hook_ready(t_info *info)
{
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->win, KEY_RELEASE, 0, &key_release, info);
	mlx_hook(info->win, RED_BUTTON, 0, &red_button_click, info);
	mlx_loop(info->mlx);
}
