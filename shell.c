#include "shell.h"


/**
 * main - main functtion of program
 * @ac: num of args
 * @av: array of args
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL; /* line from user */
	char **args = NULL; /* splited args from line */
	size_t len = 0; /* size of line */
	ssize_t read = 0; /* flag for getline */
	int status = 1; /* status of loop */

	exit_status = 0;
	(void)ac;
	while (status && read != EOF)
	{
		len = 0;
		status = isatty(STDIN_FILENO);
		if (status)
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			continue;
		}
		if (check_spaces(line))
		{
			free(line);
			status = 1;
			continue;
		}
		args = split_line(line);
		if (check_exit(args) || check_env(args))
		{
			free(line);
			free(args);
			return (exit_status);
		}
		if (*args[0] == '\0')
			continue;
		status = execute(args, av);
		free(line);
		free(args);
	}
	return (exit_status);
}

