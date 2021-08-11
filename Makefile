# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 00:16:04 by hyospark          #+#    #+#              #
#    Updated: 2021/08/12 04:18:50 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcub3d.a
BONUS_NAME = libcub3d_bonus.a
CFLAGS = -Wall -Wextra -Werror
SOURCE = src/mandatory/map_parsing/map_avail.c \
		src/mandatory/map_parsing/map_dfs.c \
		src/mandatory/map_parsing/world_map.c \
		src/mandatory/utils/convert_base.c \
		src/mandatory/utils/error_exit.c \
		src/mandatory/utils/exit.c \
		src/mandatory/utils/maplist_utils.c \
		src/mandatory/utils/memory_utils.c \
		src/mandatory/utils/rgb_utils.c \
		src/mandatory/draw_screen/dda.c \
		src/mandatory/draw_screen/floor_ceiling.c \
		src/mandatory/draw_screen/mini_map.c \
		src/mandatory/draw_screen/print_screen.c \
		src/mandatory/set_screen/cub3d.c \
		src/mandatory/set_screen/init_config.c \
		src/mandatory/set_screen/key_control.c \
		src/mandatory/set_screen/key_rotate.c \
		src/mandatory/set_screen/key_val_check.c \
		src/mandatory/set_screen/load_image.c \
		src/mandatory/set_screen/mlx_hook.c \
		src/mandatory/check_map_id/check_map_path.c \
		src/mandatory/check_map_id/check_map.c \
		src/mandatory/check_map_id/check_rgb.c \
		src/mandatory/main.c \
		src/gnl/get_next_line.c \
		src/gnl/get_next_line_utils.c \

BONUS_SOURCE = src/bonus/main_bonus.c \
		src/bonus/map_parsing/map_avail_bonus.c \
		src/bonus/map_parsing/map_dfs_bonus.c \
		src/bonus/map_parsing/world_map_bonus.c \
		src/bonus/utils/convert_base_bonus.c \
		src/bonus/utils/error_exit_bonus.c \
		src/bonus/utils/exit_bonus.c \
		src/bonus/utils/maplist_utils_bonus.c \
		src/bonus/utils/memory_utils_bonus.c \
		src/bonus/utils/rgb_utils_bonus.c \
		src/bonus/draw_screen/dda_bonus.c \
		src/bonus/draw_screen/floor_ceiling_bonus.c \
		src/bonus/draw_screen/mini_map_bonus.c \
		src/bonus/draw_screen/print_screen_bonus.c \
		src/bonus/set_screen/cub3d_bonus.c \
		src/bonus/set_screen/init_config_bonus.c \
		src/bonus/set_screen/key_control_bonus.c \
		src/bonus/set_screen/key_rotate_bonus.c \
		src/bonus/set_screen/key_val_check_bonus.c \
		src/bonus/set_screen/load_image_bonus.c \
		src/bonus/set_screen/mlx_hook_bonus.c \
		src/bonus/check_map_id/check_map_path_bonus.c \
		src/bonus/check_map_id/check_map_bonus.c \
		src/bonus/check_map_id/check_rgb_bonus.c \
		src/gnl/get_next_line.c \
		src/gnl/get_next_line_utils.c \

LIB = libft.a
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
OUT = cub3D
BONUS_OUT = cub3D_bonus
OBJECT = *.o

$(NAME): $(OBJECT)
		@echo "\033[36m ** .. Making Cub3D .. **"
		$(MAKE) bonus -C ./src/libft
		cp ./src/libft/libft.a .
		arch -x86_64 gcc $(CFLAGS) $(MLX) $(OBJECT) libft.a  -o $(OUT)
		@echo "\033[31m   ______      __   _____ ____  "
		@echo "\033[33m  / ____/_  __/ /_ |__  // __ \ "
		@echo "\033[32m / /   / / / / __ \ /_ </ / / / "
		@echo "\033[34m/ /___/ /_/ / /_/ /__/ / /_/ /  "
		@echo "\033[35m\____/\__,_/_.___/____/_____/   "
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)

$(BONUS_NAME): $(BONUS_OBJECT)
			@echo "\033[36m ** .. Making Cub3D .. **"
			$(MAKE) bonus -C ./src/libft
			cp ./src/libft/libft.a .
			arch -x86_64 gcc $(CFLAGS) $(MLX) $(BONUS_OBJECT) libft.a -o $(BONUS_OUT)
			@echo "\033[31m   ______      __   _____ ____  "
			@echo "\033[33m  / ____/_  __/ /_ |__  // __ \ "
			@echo "\033[32m / /   / / / / __ \ /_ </ / / / "
			@echo "\033[34m/ /___/ /_/ / /_/ /__/ / /_/ /  "
			@echo "\033[35m\____/\__,_/_.___/____/_____/   "
$(BONUS_OBJECT): $(BONUS_SOURCE)
	gcc $(CFLAGS) -c $(BONUS_SOURCE)
all : $(NAME)
clean:
	$(MAKE) -C ./src/libft clean
	rm -f $(OBJECT)
	rm -f $(LIB)
fclean: clean
	$(MAKE) -C ./src/libft fclean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(OUT) $(BONUS_OUT)
# rm -f $(OUT_BONUS)
# rm -f $(BONUS_NAME)

bonus: fclean $(BONUS_NAME)

re:	fclean all

.PHONY: all clean fclean re bonus