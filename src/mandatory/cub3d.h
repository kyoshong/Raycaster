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
#include "../gnl/get_next_line.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17
#define textHeight 64
#define textWidth 64
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

typedef struct	s_env
{

}				t_env;

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
	t_sprite	sprite;
	t_map		*map;
	int			**worldMap;
	int			mapHeight;
	int			mapWidth;
	int			player_x;
	int			player_y;
}				t_config;

typedef struct	s_map
{
	char			*map;
	struct s_map	*next_map_line;
}				t_map;


typedef struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct	s_info
{
	int		width;
	int		height;
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


//main
void	check_arg(int argc, char **argv);

//handle_map_id
int		check_screen(char *line, t_config *config, int i);
int		check_path(char *line, t_config *config);
int		check_path2(char *line, t_config *config);
int		check_map_id(char *line, t_config *config);

//handle_map_id2
char	*re_path(char *line, int i);
int		check_rgb(char *line, t_config *config);

//handle_map
int		check_val(t_config *config);
int		get_map(char *line, t_config *config);
int		check_map_val(char *line, t_config *config);

//print_error
void	error_exit(char *str);

//map_list
t_map	*ft_new_map(char *content);
int		ft_lstsize_map(t_map *lst);
void	ft_lstadd_back_map(t_map **lst, t_map *new);
t_map	*ft_lstlast_map(t_map *lst);
void	ft_lstclear_map(t_map **lst);

//map_avail
int		check_map_char(t_map *map, int i, int count);
void	*set_map(void *ptr, int val, size_t s);
void	make_worldMap(t_config *config, int i, int h, int w);
int		map_avail(t_config *config);

//cub3d
int		start_cub3d(t_config *config);
int		main_loop(t_info *info);
t_info	set_config(t_config *config);
int		key_release(int key, t_info *info);
int		key_press(int key, t_info *info);
int		main_loop(t_info *info);

//error print
void	error_exit(char *str);


#	endif
