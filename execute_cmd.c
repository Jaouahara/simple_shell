#include "shell.h"
/**
 * exec_cmd - a function
 * @command: a double pointer
 * @argv: adouble pointer
 * @idx: index
 * Return: 127.
 */
int exec_cmd(char **command, char **argv, int idx)
{
	pid_t child;
	char *path_cmd = NULL;
	int status;

	path_cmd = getpath(command[0]);
	if (!path_cmd)
	{
		print_error(argv[0], idx, command[0]);
		free_2(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(path_cmd, command, environ) == -1)
		{
			free(path_cmd);
			free_2(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(path_cmd);
		free_2(command);
	}

	return (WEXITSTATUS(status));
}
