NAME = libcub3d.a
CFLAGS = -Wall -Wextra -Werror
SOURCE = src/mandatory/parsing/*.c \
		src/mandatory/utils/*.c \
		src/gnl/*.c
LIB = -L. libft.a
OUT = cub3D
OBJECT = *.o
MAIN = src/mandatory/main.c

$(NAME): $(OBJECT)
	ar	rcs $(NAME) $(OBJECT)
	gcc $(MAIN) $(CFLAGS) $(LIB) -o $(OUT)
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
