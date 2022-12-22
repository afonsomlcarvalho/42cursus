#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**args1;
	char	**args2;
	int		fd[2];
	int		pipe1[2];
	int		id;
	char	*path1;
	char	*path2;

	if (argc != 5)
		exit(0);
	if (access(argv[4], F_OK) == 0)
		unlink(argv[4]);
	args1 = ft_split(argv[2], ' ');
	args2 = ft_split(argv[3], ' ');
	path1 = path_finder(env, args1[0]);
	path2 = path_finder(env, args2[0]);
	pipe(pipe1);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT, S_IRWXU);
	id = fork();
	if (id == 0)
	{
		close(pipe1[0]);
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(pipe1[1], 1);
		close(fd[0]);
		close(pipe1[1]);
		execve(path1, args1, env);
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
		execve(path2, args2, env);
	}
}
