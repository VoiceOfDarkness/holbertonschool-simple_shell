#include "shell.h"


/**
 * main - main functtion of program
 * @ac: number of args
 * @av: array of args
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL; /* line from user */
	char **args = NULL; /* splited args from line */
	ssize_t len = 0; /* size of line */
	ssize_t read = 0; /* flag for getline */
	int status = 1; /* status of loop */

	/* if status greater than 0 and user input is not EOF(End Of File) */
	while (status && read != EOF)
	{
		len = 0;
		status = isatty(STDIN_FILENO);
		if (status)
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &len, stdin);
		/* if user input is EOF */
		if (read == -1)
		{
			free(line);
			break;
		}
		if (check_spaces(line))
		{
			free(line);
			continue;
		}
		args = split_line(line);
		/* check if line contains only spaces, tabs, line breaks */
		if (*args[0] == '\0')
			continue;
		status = execute(args);
		free(line);
		free(args);
	}
	return (0);
}
