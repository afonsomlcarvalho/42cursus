NAME = pipex

SRCS =	command_struct.c \
		free.c \
		path_finder.c \
		pipex.c \

SRCSLIB = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

SRCSPR = ft_nbrlen.c \
		ft_printf.c \
		ft_putnbrs.c

SRCSLIBF = $(addprefix libft/, $(SRCSLIB))
SRCSPRF = $(addprefix printf/, $(SRCSPR))

OBJS = $(SRCS:.c=.o)
OBJSLIB = $(SRCSLIBF:.c=.o)
OBJSPR = $(SRCSPRF:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJSLIB) $(OBJSPR)
	@cc -Wall -Werror -Wextra $(OBJS) $(OBJSLIB) $(OBJSPR) -o pipex

clean:
	@rm -f *.o libft/*.o printf/*.o

fclean: clean
	@rm -f pipex

re: fclean all

.PHONY: all clean fclean re