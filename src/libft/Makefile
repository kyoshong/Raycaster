NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=ft_bzero.c ft_atoi.c ft_calloc.c \
ft_strlen.c ft_strdup.c ft_strncmp.c\
ft_memmove.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memset.c \
ft_split.c ft_strjoin.c ft_strmapi.c ft_substr.c ft_strtrim.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_itoa.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split_atoi.c\
ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c \
ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c \

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
