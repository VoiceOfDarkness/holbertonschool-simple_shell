#include "shell.h"

#define EXIT_CMD "exit"

int check_exit(char **args)
{
	if (strcmp(args[0], EXIT_CMD) == 0)
	{
		exit_status = 0;
		return (1);
	}

	return (0);
}
