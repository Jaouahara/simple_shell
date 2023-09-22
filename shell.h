#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

extern char **environ;

/* input_line.c */
char *input_line(void);

/* line_spliter.c */
char **line_spliter(char *line);

/* execute_cmd.c */
int exec_cmd(char **command, char **argv, int idx);

/* tools.c */
char *my_getenv(char *variable);
void free_2(char **array);
void print_error(char *name, int idx, char *cmd);

/* getpath.c */
char *getpath(char *command);

/* bultins */
void my_env(char **command, int *status);
void my_exit(char **command, char **argv, int *status, int idx);

/* replace_variable.c */
void replace_variable(char **command, int status);

/* handle_comments.c */
void handle_comments(char ***command);

/* string.c */
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* more_tools.c */
char *_itoa(int n);
void reverse_str(char *str, int len);
int is_num(char *str);
int _atoi(char *str);

#endif
