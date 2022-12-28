/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:50:39 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/28 15:07:17 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	*new_command(char *comm, char **env)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	cmd->args = ft_split(comm, ' ');
	cmd->path = path_finder(env, cmd->args[0]);
	cmd->next = NULL;
	return (cmd);
}

void	fd_creator(int	argc, char **argv, int *fd0, int *fd1)
{
	if (argc != 5)
		exit(0);
	if (access(argv[4], F_OK) == 0)
		unlink(argv[4]);
	*fd1 = open(argv[4], O_WRONLY | O_CREAT, S_IRWXU);
	if (access(argv[1], F_OK) == 0)
		*fd0 = open(argv[1], O_RDONLY);
	else
	{
		ft_printf("bash: %s: %s\n", argv[1], strerror(errno));
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_command	*cmd;
	int			i;

	
	new_command(argv[2], env);
	fd_creator(argc, argv, &fd[0], &fd[1]);
	args1 = ft_split(argv[2], ' ');
	args2 = ft_split(argv[3], ' ');
	path1 = path_finder(env, args1[0]);
	path2 = path_finder(env, args2[0]);
	pipe(pipe1);
	id = fork();
	if (id == 0 && fd[0])
	{
		close(pipe1[0]);
		close(fd[1]);
		dup2(fd[0], 0);
		if (ft_strncmp(path1, "Error", 5))
			dup2(pipe1[1], 1);
		close(fd[0]);
		close(pipe1[1]);
		execve(path1, args1, env);
		ft_printf("%s: command not found\n", args1[0]);
	}
	else if (id != 0)
	{
		wait(NULL);
		close(fd[0]);
		close(pipe1[1]);
		dup2(pipe1[0], 0);
		if (ft_strncmp(path2, "Error", 5))
			dup2(fd[1], 1);
		close(pipe1[0]);
		close(fd[1]);
		execve(path2, args2, env);
		ft_printf("%s: command not found\n", args2[0]);
	}
}
