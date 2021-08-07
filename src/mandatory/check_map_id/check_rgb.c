/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:42 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/08 02:05:00 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*re_path(char *line, int i)
{
	int start;

	while (line[i] == ' ')
		i++;
	start = i;
	while (line[i] != ' ')
		i++;
	if (i > start)
		return (ft_substr(line, start, i));
	return (NULL);
}

void	check_rgb(char *line, t_config *config, int val_start)
{
	char	*tem;
	int		i;
	int		*rgb;

	i = val_start + 1;
	while (line[i] != ' ')
		i++;
	if ((tem = ft_substr(line, i, ft_strlen(line))) == NULL)
		buf_error_exit("RGB_VALUE_ERROR", line, config);
	if (line[val_start] == 'F' && config->east != NULL)
	{
		if ((rgb = ft_split_atoi(tem, ',')) == NULL || config->check_val[4])
		{
			free(tem);
			buf_error_exit("Floor_RGB_VALUE_ERROR", line, config);
		}
		config->floor = convert_rgb(rgb);
		config->check_val[4] = 1;
	}
	else if ((line[val_start] == 'C') && (config->floor >= 0))
	{
		if((rgb = ft_split_atoi(tem, ',')) == NULL || config->check_val[5])
		{
			free(tem);
			buf_error_exit("Ceilling_RGB_VALUE_ERROR", line, config);
		}
		config->ceiling = convert_rgb(rgb);
		config->check_val[5] = 1;
	}
	free(tem);
}
