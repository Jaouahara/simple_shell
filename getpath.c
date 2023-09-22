#include "shell.h"
/**
 * getpath - a function
 * @command: a double pointer
 * Return: NULL, or path
 */
char *getpath(char *command)
{
	int i;
	char *path, *directory, *PATH;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				path = _strdup(command);
				return (path);
			}
			return (NULL);
		}
	}
	PATH = my_getenv("PATH");
	if (PATH == NULL)
		return (NULL);

	directory = strtok(PATH, ":");
	while (directory)
	{
		path = malloc(_strlen(directory) + _strlen(command) + 2);

		_strcpy(path, directory);
		_strcat(path, "/");
		_strcat(path, command);
		if (stat(path, &st) == 0)
		{
			free(PATH);
			return (path);
		}
		free(path);
		path = NULL;
		directory = strtok(NULL, ":");
	}
	free(PATH);
	return (NULL);
}
