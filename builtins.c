#include "shell.h"

#define EXIT_CMD "exit"
#define ENV_CMD "env"

/**
 * check_exit - checks if the user typed exit
 *
 * @args: the arguments passed to the shell
 *
 * Return: 1 if the user typed exit, 0 otherwise
*/
int check_exit(char **args)
{
	if (strcmp(args[0], EXIT_CMD) == 0)
	{
		return (1);
	}

	return (0);
}

/**
 * check_env - checks if the command is env
 *
 * @args: arguments
 *
 * Return: enviroment variables, 0 if not
*/
int check_env(char **args)
{
	int i = 0;

	if (args[0] && strcmp(args[0], "env") == 0)
	{
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (1);
	}

	return (0);
}
