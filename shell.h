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

extern char **environ;

char **div_arg(char *line);
int _execute(char **command, char **av);
char *read_line(int status);
void free_arg(char **command);
int main(int ac, char **av);
char *_strdup(const char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *str);
void freeing(char **ar);

/* getexe.c */
char **div_arg(char *line);
int _execute(char **command, char **av);
char *read_line(int status);
void free_arg(char **command);

/* main.c */
int main(int ac, char **av);

/*string.c*/
char *_strdup(const char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *str);

#endif
