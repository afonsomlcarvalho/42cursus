/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:26:25 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/06 16:12:36 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	*struct_creator(int argc, char **argv, char **env)
{
	t_command	*command;

	if (argc < 5)
		exit(0);
	if (*++argv)
	{
		command = malloc(sizeof(t_command));
		if (!command)
			return (NULL);
		command->args = ft_split(*argv, ' ');
		command->path = path_finder(env, command->args[0]);
		command->next = struct_creator(argc, argv, env);
	}
	else
		return (NULL);
	return (command);
}

t_command	*last_command(t_command *com)
{
	while (com->next)
		com = com->next;
	return (com);
}

t_command	*second_to_last(t_command *com)
{
	while (com->next != last_command(com))
		com = com->next;
	return (com);
}

void	no_infile(t_command **com)
{
	ft_printf("zsh: no such file or directory: %s\n", (*com)->args[0]);
	(*com) = (*com)->next;
	(*com)->pip[0] = open("no_infile", O_CREAT);
}