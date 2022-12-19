#include "pipex.h"

int	main()
{
	int	id;

	id = fork();
	if (id == 0)
	{
		printf("Child id: %d\n", getpid());
	}
	else
	{
		wait(NULL);
		printf("Parent id: %d\nChild's id: %d\n", getpid(), id);
	}
}
