#include "pipex.h"

void	exec_command(t_command **com, char **env, int out_fd)
{
	int	id;

	pipe((*com)->next->pip);
	id = fork();
	if (id == 0)
	{
		dup2((*com)->pip[0], 0);
		close((*com)->pip[0]);
		if ((*com)->next != second_to_last(*com))
		{
			dup2((*com)->next->pip[1], 1);
			close((*com)->next->pip[1]);
		}
		else
		{
			dup2(out_fd, 1);
			close(out_fd);
		}
		execve((*com)->next->path, (*com)->next->args, env);
	}
	else
	{
		close((*com)->next->pip[1]);
		close((*com)->pip[0]);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_command	*com;
	int	out_fd;

	com = struct_creator(argc, argv, env);
	out_fd = open(last_command(com)->args[0], O_WRONLY | O_CREAT, S_IRWXU);
	com->pip[0] = open(com->args[0], O_RDONLY);
	while (com->next != last_command(com))
	{
		exec_command(&com, env, out_fd);
		com = com->next;
	}
	while (argc-- > 3)
		wait(NULL);
}
