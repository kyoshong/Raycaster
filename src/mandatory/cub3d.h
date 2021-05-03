#ifndef _CUB3D_H
#define _CUB3D_H

#include "key_h.h"
#include "../../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "get_next_line.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17
#define textHeight 64
#define textWidth 64
#define mapWidth 24
#define mapHeight 24
#define numSprites 19
#define uDiv 1
#define vDiv 1
#define vMove 0.0

typedef	enum	e_error
{
	SUCCESS,
	ERROR,
	ARG_ERROR_TOO_FEW,
	ARG_ERROR_TOO_MANY,
	FILE_NAME_ERROR,
	SAVE_FLAG_ERROR,
	PATH_ERROR,
	RGB_VALUE_ERROR,
	SCREEN_VALUE_ERROR,
	MAP_FILE_ERROR,
	NOT_ENOUGH_CONFIG,
	MAP_ERROR,
	NEW_MAP_ERROR,
	UNAVAILABLE_MAP_ERROR,
	WRONG_MAP_CAHR,
	MAP_POS_ERROR,
}			t_error;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_config
{
	int		screen_width;
	int		screen_height;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*sprite;
	int		*floor;
	int		*ceiling;
	int		check_val[9];
	t_map	*map;
}				t_config;

typedef struct	s_map
{
	int		*map_line;
	t_map	*next_map_line;
}				t_map;

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct	s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_esc;
	t_img	img;
	int		**buf;
	double	*zBuffer;
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

typedef	struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

int		check_screen(char *line, t_config *config, int i);
char	*re_path(char *line, int i);
int		check_path(char *line, t_config *config);
int		check_rgb(char *line, t_config *config);
int		check_map(char *line,t_config *config);
int		check_arg(int argc, char **argv);
void	print_error(int error);
int		check_val(t_config *config);

//handle_map

void	ft_lstdelone(t_map *lst, void (*del)(void *));
void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_new_map(char *content);
int		get_map(char *line, t_config *config);
int		check_map_val(char *line, t_config *config);
void	print_error(int error);

#	endif