#include "shell.h"
/**
 * main - Entry points
 * @ac: a number of arg
 * @av: a double pointer of arg
 * Return: status
 */
int main(int ac, char **av)
{
	char *line = NULL, **command = NULL;
	int status = 0, index = 0;
	(void)ac;

	while (1 != 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		line = input_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		command = line_spliter(line);
		handle_comments(&command);
		if (!command)
			continue;

		replace_variable(command, status);

		if (_strcmp(command[0], "env") == 0)
			my_env(command, &status);

		else if (_strcmp(command[0], "exit") == 0)
			my_exit(command, av, &status, index);
		else
			status = exec_cmd(command, av, index);
	}
}
