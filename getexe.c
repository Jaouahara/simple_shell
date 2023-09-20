#include "shell.h"

/**
* div_arg - tokenizer a string into an array of arguments
* @line: the inpute string to be tokenized
* Return: pointer to an array of string or NULL on failure
*/
char **div_arg(char *line)
{
	char *token = NULL, *dup = NULL;
	char **command = NULL;
	int i = 0, t = 0;

	if (!line)
		return (NULL);
	dup = strdup(line);
	token = strtok(dup, " \t\n");
	/* calc number of argm */
	while (token)
	{
		i++;
		token = strtok(NULL, " \t\n");
	}
	free(dup), dup = NULL;

	command = malloc(sizeof(char *) * (i + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		command[t] = strdup(token);
		token = strtok(NULL, " \t\n");
		t++;
	}
	command[t] = NULL;
	return (command);
}

/**
* _execute - execute a command in a new process
* @command: an array of strings representing the command and its arguments
* @av: an array of strings
* Return: 0 on success, 1 on error
*/
int _execute(char **command, char **av)
{
	pid_t child_pid;
	int status = 0;

	if (!command)
		return (1);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror(av[0]);
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);

}

/**
* read_line - read a line from standard input
* @status: the exit status to use if an error occurs
* Return: line
*/
char *read_line(int status)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		exit(status);
	}

	return (line);
}

/**
* free_arg - free memory allocated for an array of string
* @command: the array of string to be freed
*/
void free_arg(char **command)
{
	int i = 0;
	if (command != NULL)
	{
		while (command[i])
		{
			free(command[i]);
			i++;
		}
		free(command);
	}
}