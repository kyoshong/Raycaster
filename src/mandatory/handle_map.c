
#include "cub3d.h"

t_map	*ft_new_map(char *content)
{
	t_map	*n_con;

	if (!(n_con = (t_map *)malloc(sizeof(*n_con))))
		return (NULL);
	n_con->map_line = content;
	n_con->next_map_line = NULL;
	return (n_con);
}

int get_map(char *line, t_config *config)
{
	t_map *map;
	if (!(map = ft_new_map(line)))
		return (NEW_MAP_ERROR);
	ft_lstadd_back(&(config->map->map_line), &map);
	return (SUCCESS);
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map *temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next_map_line = new;
}

void	ft_lstdelone(t_map *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->next_map_line);
	free(lst);
}

int		check_map_val(char *line, t_config *config)
{
	int i;
	
	if (check_val(&config) > 0)
		return (NOT_ENOUGH_CONFIG);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) && get_map(line, &config))
	{
		return (SUCCESS);
	}
	else
		return (MAP_ERROR);
}
