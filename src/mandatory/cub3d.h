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
#include "get_next_line_bonus.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17
#define textHeight 64
#define textWidth 64
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480
#define numSprites 19
#define uDiv 1
#define vDiv 1
#define vMove 0.0

// typedef	enum	e_error
// {
// 	SUCCESS,
// 	ERROR,
// 	ARG_ERROR_TOO_FEW,
// 	ARG_ERROR_TOO_MANY,
// 	FILE_NAME_ERROR,
// 	SAVE_FLAG_ERROR
// }			t_error;

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

typedef struct	s_arg
{
	int		screen_width;
	int		screen_height;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*sprite;
	char	*floor;
	char	*ceiling;
	t_map	*map;

}				t_arg;

typedef struct	s_map
{
	

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
	int		buf[height][width];
	double	zBuffer[width];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

typedef	struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

#	endif