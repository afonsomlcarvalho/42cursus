/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorais- <amorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:26:41 by amorais-          #+#    #+#             */
/*   Updated: 2023/01/05 14:12:42 by amorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "printf/ft_printf.h"
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_command	t_command;

struct s_command
{
	char		*path;
	char		**args;
	int			pip[2];
	t_command	*next;
};

char		*path_finder(char **env, char *command);
t_command	*struct_creator(int argc, char **argv, char **env);
t_command	*last_command(t_command *com);
t_command	*second_to_last(t_command *com);
void		command_clear(t_command **com);
void		free_split(char **array, int x);
void		command_verifier(t_command **com);
void		error_management(t_command *com);
#endif