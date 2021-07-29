/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 17:35:39 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/29 03:44:17 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "key_h.h"
#include "../../mlx/mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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

typedef struct	s_map
{
	char			*map_line;
	struct s_map	*next_map_line;
}				t_map;

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

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
	t_sprite	sprite_s;
	int			sprite_ver;
	t_map		*map;
	int			**worldMap;
	int			mapHeight;
	int			mapWidth;
	t_player	player;

}				t_config;

typedef struct	s_info
{
	int			width;
	int			height;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	void		*mlx;
	void		*win;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_esc;
	t_img		img;
	int			**buf;
	double		zBuffer[640];
	int			**texture;
	double		moveSpeed;
	double		rotSpeed;
	t_config	*config;
}				t_info;

typedef struct s_wall
{
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	double wallX;
	int texX;
	int texY;
	double step;
	double texPos;
	int color;
	int textNum;
}				t_wall;

typedef	struct s_floor
{
	float rayDirX0;
	float rayDirY0;
	float rayDirX1;
	float rayDirY1;
	int p;
	float posZ;
	float rowDistance;
	float floorStepX;
	float floorStepY;
	float floorX;
	float floorY;
	int cellX;
	int cellY;
	int tx;
	int ty;
	int	checkPattern;
	int floorTexture;
	int ceilingTexture;
	int color;
	int x;
	int y;
}				t_floor;

//main
void		check_arg(int argc, char **argv);
t_config	*init_config();

//handle_map_id
int		check_screen(char *line, t_config *config, int i);
void	check_path(char *line, t_config *config);
void	check_path2(char *line, t_config *config);
void	check_map_id(char *line, t_config *config);

//handle_map_id2
char	*re_path(char *line, int i);
void	check_rgb(char *line, t_config *config, int val_start);

//handle_map
int		check_val(t_config *config);
void	get_map(char *line, t_config *config);
int		check_map_val(char *line, t_config *config);

//print_error
void	error_exit(char *str);
void	buf_free_error_exit(char *str, char *buf);
void	free_all_error_exit(t_map *map, char *str, char *buf);


//map_list
t_map	*ft_new_map(char *content);
void	ft_lstadd_back_map(t_map **lst, t_map *new);
t_map	*ft_lstlast_map(t_map *lst);
void	ft_lstclear_map(t_map *map_struct);

//map_avail
int		check_map_char(t_config *config, int i, int count);
int		*make_map_arr(int s);
void	make_worldMap(t_config *config);
void	map_avail(t_config *config);
int		check_map_char_sprite(t_config *config, int i, int count);

//map_dfs
void	dfs_map_check(t_config *config);
void	dfs_map(t_config *t, int **map, int x, int y);

//cub3d
void	start_cub3d(t_config *config);
void	set_config(t_config *config, t_info *info);
int		main_loop(t_info *info);
void	cal_dda(t_info *info);
void	set_texture(t_info *info);
void	print_floor_ceilling(t_info *info);



//error print
void	error_exit(char *str);
void	buf_free_error_exit(char *str, char *buf);
void	free_map_error_exit(t_map *map, char *str);
void	free_all_error_exit(t_map *map, char *str, char *buf);


////////////

//key_control
int		key_release(int key, t_info *info);
int		key_press(int key, t_info *info);
void	key_update(t_info *info);

//load_image
void	load_image(t_info *info, int *texture, char *path, t_img *img);
void	load_texture(t_info *info);

# endif
