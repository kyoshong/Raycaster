/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 01:45:52 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/13 18:26:14 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "key_bonus.h"
# include "../../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "gnl/get_next_line_bonus.h"
# include <stdio.h>
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define RED_BUTTON 17
# define TEXT_HEIGHT 128
# define TEXT_WIDTH 128
# define PICS_NUM 4

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next_map_line;
}				t_map;

typedef struct s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}				t_img;

typedef struct s_player
{
	int				x;
	int				y;
	int				num;
}				t_player;

typedef struct s_config
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*sprite;
	int				floor;
	int				ceiling;
	int				check_val[6];
	int				sprite_ver;
	t_map			*map;
	int				**worldMap;
	int				mapHeight;
	int				mapWidth;
	t_player		player;
}				t_config;

typedef struct s_info
{
	int				width;
	int				height;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	void			*mlx;
	void			*win;
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_AR_L;
	int				key_AR_R;
	int				key_esc;
	t_img			img;
	int				**buf;
	double			zBuffer[1280];
	int				**texture;
	double			moveSpeed;
	double			rotSpeed;
	t_config		*config;
}				t_info;

typedef struct s_wall
{
	double			camera;
	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;
	double			firstDistX;
	double			firstDistY;
	double			nextDistX;
	double			nextDistY;
	double			flatWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	double			wallX;
	int				texX;
	int				texY;
	double			step;
	double			texPos;
	int				color;
	int				textNum;
}				t_wall;

typedef struct s_horizon
{
	float			rayDirX0;
	float			rayDirY0;
	float			rayDirX1;
	float			rayDirY1;
	int				p;
	float			posZ;
	float			rowDistance;
	float			floorStepX;
	float			floorStepY;
	float			floorX;
	float			floorY;
	int				cellX;
	int				cellY;
	int				tx;
	int				ty;
	int				checkPattern;
	int				floorTexture;
	int				ceilingTexture;
	int				ceilingcolor;
	int				floorcolor;
	int				x;
	int				y;
}				t_horizon;

void		check_arg(int argc, char **argv);
t_config	*init_config(void);
int			check_screen(char *line, t_config *config, int i);
void		check_path_we(char *line, t_config *config);
void		check_path_ns(char *line, t_config *config);
void		check_map_id(char *line, t_config *config);
char		*re_path(char *line, int i);
void		check_rgb(char *line, t_config *config, int val_start, int i);
int			check_val(t_config *config);
void		get_map(char *line, t_config *config);
int			check_map_val(char *line, t_config *config);
void		key_forword(t_info *info);
t_map		*ft_new_map(char *content);
void		ft_lstadd_back_map(t_config *config, t_map *n);
t_map		*ft_lstlast_map(t_map *lst);
void		ft_lstclear_map(t_map *map_struct);
int			check_map_char(t_config *config, int i, int count);
int			*make_map_arr(int s);
void		make_worldMap(t_config *config);
void		map_avail(t_config *config);
int			check_map_char_sprite(t_config *config, int i, int count);
void		dfs_map_check(t_config *config);
void		dfs_map(t_config *t, int **map, int x, int y);
void		draw(t_info *info);
void		ray_dir(t_info *info, t_wall *wall);
void		cal_distance(t_info *info, t_wall *wall);
void		check_hit(t_info *info, t_wall *wall);
void		get_ratio(t_info *info, t_wall *wall);
void		set_textureNum(t_wall *wall);
void		dda(t_info *info, int x, int i);
void		print_floor_ceilling(t_info *info);
void		start_cub3d(t_config *config);
void		set_config(t_config *config, t_info *info);
int			main_loop(t_info *info);
void		set_texture(t_info *info, int i, int j);
void		free_arr(int **arr, int i);
void		config_path_free(t_config *config);
void		error_exit(char *str);
void		buf_error_exit(char *str, char *buf, t_config *config);
void		map_avail_error_exit(t_config *config, char *str);
void		esc_exit(t_info *info);
void		cub3d_error_exit(t_info *info, char *str);
void		cub3d_free_all(t_info *info);
void		free_worldMap(t_config *config);
void		set_buf(t_info *info);
int			convert_rgb(int *rgb_int);
char		*ft_strAppend(char *s1, char *s2, char *s3);
int			ft_get_base_count(int n);
int			ft_count_base(int n, int i);
char		*ft_get_upper_str(int n);
char		*ft_strrev(char *s);
int			key_release(int key, t_info *info);
int			key_press(int key, t_info *info);
void		key_update(t_info *info);
void		key_right(t_info *info);
void		key_left(t_info *info);
int			red_button_click(t_info *info);
void		key_right_rotate(t_info *info);
void		key_left_rotate(t_info *info);
void		mini_map(t_info *info);
void		convert_image(t_info *info, int *texture, char *path, t_img *img);
void		load_texture(t_info *info);
void		mlx_hook_ready(t_info *info);
void		rgb_error_exit(char *str, char *buf, t_config *config, char *tem);

#	endif
