all:
	gcc -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c *.c
	gcc *.o -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o tester

clean:
	rm -f *.o

fclean: clean
	rm -f tester