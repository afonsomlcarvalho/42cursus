/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:26:29 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/06 10:19:24 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **array, int x)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (i != x)
			free(array[i]);
		i++;
	}
	free(array);
}

void	command_clear(t_command **com)
{
	t_command	*temp;

	while (*com)
	{
		temp = (*com)->next;
		free_split((*com)->args, -1);
		free((*com)->path);
		free(*com);
		(*com) = temp;
	}
	(*com) = NULL;
}

void	error_management(t_command **com, int error_code)
{
	if (error_code == 0)
	{
		perror("Pipe failed");
		command_clear(com);
		exit(0);
	}
	if (error_code == 1)
	{
		perror("Fork failed");
		command_clear(com);
		exit(0);
	}
	if (error_code == 2)
	{
		ft_printf("zsh: command not found: %s\n", (*com)->next->args[0]);
		exit(0);
	}
}
