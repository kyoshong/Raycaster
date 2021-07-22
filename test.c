#include <stdio.h>
#include <stdlib.h>
typedef struct	s_player
{
	int		x;
	int		y;
	int		num;
}				t_player;

typedef struct	s_config
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	int			*floor;
	int			*ceiling;
	int			check_val[6];
	int			numSprites;
	int			sprite_ver;
	int			**worldMap;
	int			mapHeight;
	int			mapWidth;
	t_player	player;

}				t_config;

int main(int argc, char const *argv[])
{
	t_config *config;
	t_config *config2;
	config = malloc(sizeof(config));
	config2 = malloc(sizeof(*config2));
	printf("%lu\n", sizeof(*config));
	printf("%lu\n", sizeof(config2));

	return 0;
}
