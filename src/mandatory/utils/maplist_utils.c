/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplist_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:37:14 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/10 21:34:19 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*ft_new_map(char *content)
{
	t_map	*map_struct;

	map_struct = (t_map *)malloc(sizeof(*map_struct));
	if (map_struct == NULL)
		return (NULL);
	map_struct->map_line = ft_strdup(content);
	map_struct->next_map_line = NULL;
	return (map_struct);
}

t_map	*ft_lstlast_map(t_map *map_struct)
{
	if (!map_struct)
		return (NULL);
	while (map_struct->next_map_line)
	{
		map_struct = map_struct->next_map_line;
	}
	return (map_struct);
}

void	ft_lstadd_back_map(t_config *config, t_map *new)
{
	t_map *tem;
	
	if (!new)
		return ;
	if (config->map == NULL)
	{
		config->map = new;
		return ;
	}
	tem = config->map;
	while (tem->next_map_line != NULL)
	{
		tem = tem->next_map_line;
	}
	tem->next_map_line = new;
}

void	ft_lstclear_map(t_map *map_struct)
{
	t_map *temp;

	if (map_struct == NULL)
		return ;
	while (1)
	{
		temp = map_struct->next_map_line;
		free(map_struct->map_line);
		free(map_struct);
		if (temp == NULL)
			break ;
		map_struct = temp;
	}
}
