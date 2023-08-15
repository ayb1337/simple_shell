#ifndef _MAIN_H
#define _MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/* External variables */
extern char **environ;
char env_vars[MAX_ENV_VARS][MAX_VAR_LENGTH];
char env_vals[MAX_ENV_VARS][MAX_VALUE_LENGTH];
int num_vars = 0;

/* Utilities functions */
int _printf(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

/* Shell functions */
void prompt(void);
void execmd(char **argv, char *argv_0);
char *get_path(char *command);
void print_environment(void);
int exit_builtin(char **tokens);
int _setenv(char *variable, char *value);
int _unsetenv(char *variable);

/* Split command utility functions */
int get_number_of_tokens(char *command, const char *delim);
char **tokenize_input(char *line_copy, const char *delim, int num_tokens);
int memory_allocation_error(void);


#endif /* _MAIN_H */
