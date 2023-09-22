#include "shell.h"
/**
 * handle_comments - a function
 * @command: a double pointer
 */
void handle_comments(char ***command)
{
	int i, comment;

	if (!(*command))
		return;

	comment = 0;

	for (i = 0; (*command)[i]; i++)
	{
		if ((*command)[i][0] == '#')
		{
			comment = 1;
			break;
		}
	}
	if (comment == 1)
	{
		while ((*command)[i])
		{
			free((*command)[i]);
			(*command)[i] = NULL;
			i++;
		}
	}
	if ((*command)[0] == NULL)
	{
		free((*command));
		(*command) = NULL;
	}
}
