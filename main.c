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
	int status = 0; 
	(void)ac;

	while (1)
	{
		line = read_line(status);
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		command = div_arg(line);
		if (!command)
			continue;
		/*i = 0;
		while (command[i] != NULL)
		{
			printf("%s\n", command[i]);
			i++;
		}
		free_arg(command);
		free(line);*/

		status = _execute(command, av);
	}
	/*return (status);*/
}
