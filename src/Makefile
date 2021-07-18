NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SOURCE = 

LIB = -L. -lpushswap
MAIN = src/mandantory/main.c
OUT = cub3D
OBJECT = 

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
