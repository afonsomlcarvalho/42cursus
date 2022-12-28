NAME = pipex

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) *.c printf/*.c libft/*.c

clean:
	rm -f *.o

fclean: clean
	rm -f pipex

re: fclean all

.PHONY: all clean fclean re