#include <stdio.h>
#include <stdlib.h>

typedef struct	s_map
{
	char			*map;
	struct s_map	*next_map_line;
}				t_map;

typedef struct	s_config
{
	int			width;
	int			height;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	int			*floor;
	int			*ceiling;
	int			check_val[9];
	int			numSprites;
	t_map		*map;
	int			**worldMap;
	int			mapHeight;
	int			mapWidth;
	int			player_x;
	int			player_y;
}				t_config;

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

t_map	*ft_new_map(char *content)
{
	t_map	*n_con;

	if (!(n_con = (t_map *)malloc(sizeof(*n_con))))
		return (NULL);
	n_con->map = content;
	n_con->next_map_line = NULL;
	return (n_con);
}

int		get_map(char *line, t_config *config)
{
	t_map *map;

	if (!(map = ft_new_map(line)))
		return (1);
	ft_lstadd_back_map(&(config->map), map);
	return (1);
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

void	free_error_exit(t_map **map, char *str)
{
	ft_lstclear_map(map);
	printf("ERROR\n%s", str);
	exit(1);
}


int main(int argc, char const *argv[])
{
	t_config config;
	char *str = "wow";
	char *str1 = "f";
	t_map *tem;

	get_map(str, &config);
	get_map(str1, &config);
	tem = config.map;
	while (1)
	{
		printf("%s\n", tem->map);
		if (tem->next_map_line == NULL)
			break ;
		tem = tem->next_map_line;
	}
	ft_lstclear_map(&(config.map));
	// while (1)
	// {
	// 	printf("%s\n", tem->map);
	// 	if (tem->next_map_line == NULL)
	// 		break ;
	// 	tem = tem->next_map_line;
	// }
	return 0;

}
