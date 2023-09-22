#include "shell.h"

/**
 * my_env - a function
 * @command: a double pointer
 * @status: integer
 */
void my_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
	free_2(command);
}
/**
 * my_exit - a function
 * @command: a double pointer
 * @argv: adouble pointer
 * @status: integer
 * @idx: index
 */
void my_exit(char **command, char **argv, int *status, int idx)
{
	char *index;
	char mssg[] = ": exit: Illegal number: ";
	int exit_val = (*status);

	if (command[1])
	{
		if (!is_num(command[1]))
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			(*status) = 2;
			free(index);
			free_2(command);

			return;
		}
		else
			exit_val = _atoi(command[1]);
	}
	free_2(command);
	exit(exit_val);
}
