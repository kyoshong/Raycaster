
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

void	ft_lstadd_back_map(t_map **lst, t_map *new)
{
	t_map *temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast_map(*lst);
	temp->next_map_line = new;
}

t_map	*ft_lstlast_map(t_map *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next_map_line)
	{
		lst = lst->next_map_line;
	}
	return (lst);
}


void	ft_lstclear_map(t_map **lst)
{
	t_map *temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next_map_line;
		free(lst);
		*lst = temp;
	}
	*lst = NULL;
}