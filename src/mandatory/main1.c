#include "cub3d.h"

int	check_map(char *line)
{
	if (line[0] == 'R')
	{

	}
	else if (line[0] ==)
}
int	check_arg(int argc, char **argv)
{
	int a;
	if (argc < 2)
	{
		printf("ERROR\nARG_ERROR_TOO_FEW");
		return(1);
	}
	if (argc > 3)
	{
		printf("ERROR\nARG_ERROR_TOO_MANY");
		return(1);
	}
	a = ft_strlen(argv[1]);
	if (argc == 2 && ft_strncmp(ft_substr(argv[1], a - 4, 4), ".cub", 4) != 0)
	{
		printf("ERROR\nFILE_NAME_ERROR");
		return(1);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0)
	{
		printf("ERROR\nSAVE_FLAG_ERROR");
		return(1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int		fd;
	int 	check;
	char	*buf;

	if (arg_check(argc, argv))
		return (0);
	fd = open(argv[1], O_RDWR);
	while ((check = get_next_line(fd, &buf)) > 0)
	{
		
	}
	
	return 0;
}
