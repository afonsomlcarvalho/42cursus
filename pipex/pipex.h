#ifndef PIPEX_H
# define PIPEX_H

# include "printf/ft_printf.h"
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

char	*path_finder(char **env, char *command);
#endif