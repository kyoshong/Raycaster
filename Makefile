NAME = libcub3d.a
CFLAGS = -Wall -Wextra -Werror
SOURCE = src/mandatory/parsing/*.c \
		src/mandatory/utils/*.c \
		src/mandatory/draw_screen/*.c \
		src/gnl/*.c
LIB = libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit
OUT = cub3D
OBJECT = *.o
MAIN = src/mandatory/main.c

$(NAME): $(OBJECT)
	ar	rcs $(NAME) $(OBJECT)
	arch -x86_64 gcc $(MAIN) $(CFLAGS) $(LIB) $(NAME) -o $(OUT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)

all : $(NAME)
clean:
	@rm -f $(OBJECT)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OUT)
bonus: fclean all

re:	fclean all

.PHONY: all clean fclean re bonus
