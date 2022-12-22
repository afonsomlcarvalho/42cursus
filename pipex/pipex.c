#include "pipex.h"

int	main(int argc, char **argv)
{
	char	**args1;
	char	**args2;
	int		fd[2];
	int		pipe1[2];
	int		id;

	if (argc != 5)
		exit(0);
	args1 = ft_split(argv[2], ' ');
	args2 = ft_split(argv[3], ' ');
	pipe(pipe1);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT);
	id = fork();
	if (id == 0)
	{
		close(pipe1[0]);
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(pipe1[1], 1);
		close(fd[0]);
		close(pipe1[1]);
		execvp(args1[0], args1);
	}
	else
	{
		wait(NULL);
		close(fd[0]);
		close(pipe1[1]);
		dup2(pipe1[0], 0);
		dup2(fd[1], 1);
		close(pipe1[0]);
		close(fd[1]);
		execvp(args2[0], args2);
	}
}
