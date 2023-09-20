#include "shell.h"

/**
 * main - main function
 * @ac: arguments count
 * @av: arguments vector
 * Return: status
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, i = 0;
	(void)ac, (void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		line = read_line(status);

		command = div_arg(line);
		i = 0;
		while (command[i] != NULL)
		{
			printf("%s\n", command[i]);
			i++;
		}
		free_arg(command);
		free(line);
	}
	return (status);
}
