#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	i;

	(void) argc;
	(void) argv;
	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}