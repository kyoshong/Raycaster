# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 00:16:04 by hyospark          #+#    #+#              #
#    Updated: 2021/07/31 15:00:44 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcub3d.a
BONUS_NAME = libcub3d.a
CFLAGS = -Wall -Wextra -Werror
SOURCE = src/mandatory/map_parsing/*.c \
		src/mandatory/utils/*.c \
		src/mandatory/draw_screen/*.c \
		src/gnl/*.c
BONUS_SOURCE = src/bonus/map_parsing/*.c \
		src/bonus/utils/*.c \
		src/bonus/draw_screen/*.c \
		src/gnl/*.c
LIB = libft.a
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
OUT = cub3D
OBJECT = *.o
MAIN = src/mandatory/main.c

$(NAME): $(OBJECT)
	$(MAKE) bonus -C ./src/libft
	cp ./src/libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)
	arch -x86_64 gcc $(MAIN) $(CFLAGS) $(MLX) $(NAME) -o $(OUT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)
$(BONUS_NAME): $(BONUS_OBJECT)
	$(MAKE) bonus -C ./src/libft
	cp ./src/libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)
	arch -x86_64 gcc $(MAIN) $(CFLAGS) $(MLX) $(NAME) -o $(OUT)
$(BONUS_OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)
all : $(NAME)
clean:
	$(MAKE) -C ./src/libft clean
	rm -f $(OBJECT)
fclean: clean
	$(MAKE) -C ./src/libft fclean
	rm -f $(NAME)
	rm -f $(OUT)
bonus: fclean $(BONUS_NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
