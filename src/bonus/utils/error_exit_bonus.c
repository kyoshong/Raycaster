/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:02:52 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 03:40:47 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	buf_error_exit(char *str, char *buf, t_config *config)
{
	printf("ERROR\n%s", str);
	free(buf);
	config_path_free(config);
	free(config);
	exit(1);
}

void	rgb_error_exit(char *str, char *buf, t_config *config, char *tem)
{
	printf("ERROR\n%s", str);
	free(tem);
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
