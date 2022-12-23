/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:50:39 by amorais-          #+#    #+#             */
/*   Updated: 2022/12/23 14:05:24 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	fd[1] = open(argv[4], O_WRONLY | O_CREAT, S_IRWXU);
	if (access(argv[1], F_OK) == 0)
		fd[0] = open(argv[1], O_RDONLY);
	if (!(fd[0]))
		ft_printf("bash: %s: %s\n", argv[1], strerror(errno));
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
