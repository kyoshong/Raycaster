/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:37:14 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/23 00:30:50 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*ft_new_map(char *content)
{
	t_map	*map_struct;

	map_struct = (t_map *)malloc(sizeof(*map_struct));
	if (map_struct == NULL)
		return (NULL);
	map_struct->map_line = content;
	map_struct->next_map_line = NULL;
	return (map_struct);
}

int	ft_lstsize_map(t_map *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next_map_line;
		i++;
	}
	return (i);
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

void	ft_lstadd_back_map(t_map **map_struct, t_map *new)
{
	t_map *temp;

	if (!new)
		return ;
	if (!*map_struct)
	{
		*map_struct = new;
		return ;
	}
	temp = ft_lstlast_map(*map_struct);
	temp->next_map_line = new;
}

void	ft_lstclear_map(t_map **map_struct)
{
	t_map *temp;

	if (!map_struct)
		return ;
	while (*map_struct)
	{
		temp = (*map_struct)->next_map_line;
		free(map_struct);
		*map_struct = temp;
	}
	*map_struct = NULL;
}
