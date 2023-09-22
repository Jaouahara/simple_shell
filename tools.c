#include "shell.h"
/**
 * my_getenv - a function
 * @variable: a  pointer
 * Return: a pointer
 */
char *my_getenv(char *variable)
{
	int i;
	char *key, *env_value, *tmp;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			env_value = _strdup(strtok(NULL, "\n"));
			free(tmp);
			return (env_value);
		}
		free(tmp);
	}
	return (NULL);
}
/**
 * free_2 - a function
 * @array: a  pointer
 * Return: a pointer
 */
void free_2(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}
/**
 * print_error - a function
 * @name: a  pointer
 * @idx: a pointer
 * @cmd: a pointer
 */
void print_error(char *name, int idx, char *cmd)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}
