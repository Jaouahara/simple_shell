#include "shell.h"

/**
 * freeing - free the arrays
 * @ar: the array hwo freeid
 * */
void freeing(char **ar)
{
	int i;
	if (!ar)
		return;

	for (i = 0; ar[i]; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}

	free(ar), ar = NULL;
}

