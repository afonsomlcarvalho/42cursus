#include "pipex.h"

t_command	*struct_creator(int argc, char **argv, char **env)
{
	t_command	*command;

	if (argc < 5)
		exit(0);
	if (*++argv)
	{
		command = malloc(sizeof(t_command));
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