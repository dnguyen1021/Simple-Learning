all: learn.c
	gcc -Wall -Werror -fsanitize=address -g -std=c99 -o learn learn.c
clean:
	rm learn
