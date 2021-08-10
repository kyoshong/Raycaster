# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 00:16:04 by hyospark          #+#    #+#              #
#    Updated: 2021/08/10 23:10:56 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcub3d.a
# BONUS_NAME = libcub3d_bonus.a
CFLAGS = -Wall -Wextra -Werror
SOURCE = src/mandatory/map_parsing/*.c \
		src/mandatory/utils/*.c \
		src/mandatory/draw_screen/*.c \
		src/mandatory/set_screen/*.c \
		src/mandatory/check_map_id/*.c \
		src/mandatory/*.c \
		src/gnl/*.c
# BONUS_SOURCE = src/bonus/map_parsing/*.c \
# 		src/bonus/utils/*.c \
# 		src/bonus/draw_screen/*.c \
# 		src/gnl/*.c
LIB = libft.a
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
OUT = cub3D
# OUT_BONUS = cub3D_bonus
OBJECT = *.o
# BONUS_OBJECT = *.o
# BONUS_MAIN = src/bonus/main.c

$(NAME): $(OBJECT)
	$(MAKE) bonus -C ./src/libft
	cp ./src/libft/libft.a .
	arch -x86_64 gcc $(CFLAGS) $(MLX) $(OBJECT) libft.a  -o $(OUT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)

# $(BONUS_NAME): $(BONUS_OBJECT)
# 	$(MAKE) bonus -C ./src/libft
# 	cp ./src/libft/libft.a .
# 	mv libft.a $(BONUS_NAME)
# 	ar rc $(BONUS_NAME) $(OBJECT)
# 	ranlib $(BONUS_NAME)
# 	arch -x86_64 gcc $(BONUS_MAIN) $(CFLAGS) $(MLX) $(BONUS_NAME) -o $(OUT_BONUS)

# $(BONUS_OBJECT): $(BONUS_SOURCE)
# 	gcc $(CFLAGS) -c $(BONUS_SOURCE)
all : $(NAME)
clean:
	$(MAKE) -C ./src/libft clean
	rm -f $(OBJECT)
	rm -f $(LIB)
fclean: clean
	$(MAKE) -C ./src/libft fclean
	rm -f $(NAME)
	rm -f $(OUT)
# rm -f $(OUT_BONUS)
# rm -f $(BONUS_NAME)

# bonus: fclean $(BONUS_NAME)

re:	fclean all

.PHONY: all clean fclean re bonus