#include "shell.h"
/**
 * line_spliter - a function
 * @line: a double pointer
 * Return: a double pointer.
 */
char **line_spliter(char *line)
{
	int i = 0, j = 0;
	char *token, *tmp, **array = NULL, delimeters[] = " \n\t";

	if (line == NULL)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, delimeters);
	if (!token)
	{
		free(line);
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		j++;
		token = strtok(NULL, delimeters);
	}
	free(tmp);
	array = malloc(sizeof(char *) * (j + 1));
	token = strtok(line, delimeters);
	while (token)
	{
		array[i++] = _strdup(token);
		token = strtok(NULL, delimeters);
	}
	free(line);
	array[i] = NULL;
	return (array);
}
