/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:26:38 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/06 14:08:38 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	output_decider(t_command **com, int out_fd)
{
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
}

void	exec_command(t_command **com, char **env, int out_fd, t_command **start)
{
	int	id;

	if (pipe((*com)->next->pip) == -1)
		error_management(start, 0);
	id = fork();
	if (id == -1)
		error_management(start, 1);
	if (id == 0)
	{
		if ((*com)->pip[0])
			dup2((*com)->pip[0], 0);
		close((*com)->pip[0]);
		output_decider(com, out_fd);
		execve((*com)->next->path, (*com)->next->args, env);
		error_management(com, 2);
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
	t_command	*start;
	int			out_fd;

	com = struct_creator(argc, argv, env);
	start = com;
	out_fd = open(last_command(com)->args[0], O_WRONLY | O_TRUNC | O_CREAT, \
	S_IRWXU);
	if (access(com->args[0], F_OK) == 0)
		com->pip[0] = open(com->args[0], O_RDONLY);
	else
		ft_printf("zsh: no such file or directory: %s\n", com->args[0]);
	while (com->next && com->next != last_command(com))
	{
		exec_command(&com, env, out_fd, &start);
		com = com->next;
	}
	close(com->pip[0]);
	while (argc-- > 3)
		wait(NULL);
	command_clear(&start);
}
