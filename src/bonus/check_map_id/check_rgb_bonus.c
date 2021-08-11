/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:42 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/12 03:41:34 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*re_path(char *line, int i)
{
	int	start;

	while (line[i] == ' ')
		i++;
	start = i;
	while (line[i] && line[i] != ' ')
		i++;
	if (i > start)
		return (ft_substr(line, start, i));
	return (NULL);
}

void	check_rgb(char *line, t_config *config, int val_start, int i)
{
	char	*tem;
	int		*rgb;

	while (line[i] != ' ')
		i++;
	tem = ft_substr(line, i, ft_strlen(line));
	if (tem == NULL)
		buf_error_exit("RGB_VALUE_ERROR", line, config);
	rgb = ft_split_atoi(tem, ',');
	if (rgb == NULL)
		rgb_error_exit("RGB_VALUE_ERROR", line, config, tem);
	if (line[val_start] == 'F' && config->east != NULL)
	{
		config->floor = convert_rgb(rgb);
		config->check_val[4] = 1;
	}
	else if ((line[val_start] == 'C') && (config->floor >= 0))
	{
		config->ceiling = convert_rgb(rgb);
		config->check_val[5] = 1;
	}
	else
		rgb_error_exit("RGB_VALUE_ERROR", line, config, tem);
	free(tem);
}
