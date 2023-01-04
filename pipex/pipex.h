#ifndef PIPEX_H
# define PIPEX_H

# include "printf/ft_printf.h"
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "../getnextline/get_next_line.h"

typedef struct s_command t_command;

struct s_command
{
	char		*path;
	char		**args;
	int			pip[2];
	t_command	*next;
};

char		*path_finder(char **env, char *command);
t_command	*struct_creator(int argc, char **argv, char **env);
t_command	*last_command(t_command *com);
t_command	*second_to_last(t_command *com);
#endif