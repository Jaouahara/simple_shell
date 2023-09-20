#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

char **div_arg(char *line);
int _execute(char **command, char **av);
char *read_line(int status);
void free_arg(char **command);
int main(int ac, char **av);

/**
*@line: the inpute string to be tokenized
*@command: an array of strings representing the command and its arguments
*@av: an array of strings
*@status: the exit status to use if an error occurs
*@ac: arguments count
*@av: arguments vector
*/

/* getexe.c */
char **div_arg(char *line);
int _execute(char **command, char **av);
char *read_line(int status);
void free_arg(char **command);

/* main.c */
int main(int ac, char **av);

#endif
