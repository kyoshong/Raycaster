all:
	arch -x86_64 gcc -Lmlx -lmlx -framework OpenGL -framework AppKit test.c
	./a.out
