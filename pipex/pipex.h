#ifndef PIPEX_H
# define PIPEX_H

# include "printf/ft_printf.h"
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_command t_command;

struct s_command
{
	char		*path;
	char		**args;
	int			fd[2];
	t_command	*next;
}

char	*path_finder(char **env, char *command);
#endif