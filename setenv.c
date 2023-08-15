#include "main.h"



/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @variable: the variable to add or to modify
 * @value: the value of the variable to add or to modify
 * @num_vars_ptr: pointer to the num_vars variable
 * Return: returns 0 (success)
 */
int _setenv(char *variable, char *value, int *num_vars_ptr)
{
#define MAX_ENV_VARS 100
#define MAX_VAR_LENGTH 50
#define MAX_VALUE_LENGTH 100
char env_vars[MAX_ENV_VARS][MAX_VAR_LENGTH];
char env_vals[MAX_ENV_VARS][MAX_VALUE_LENGTH];
int i;
if (*num_vars_ptr >= MAX_ENV_VARS)
{
perror("Error: Too many environment variables\n");
return (-1);
}
for (i = 0; i < *num_vars_ptr; i++)
{
if (_strcmp(env_vars[i], variable) == 0)
{
_strcpy(env_vals[i], value);
return (0);
}
}

if (_strlen(variable) >= MAX_VAR_LENGTH || _strlen(value) >= MAX_VALUE_LENGTH)
{
perror("Error: Variable or value is too long\n");
return (-1);
}
_strcpy(env_vars[*num_vars_ptr], variable);
_strcpy(env_vals[*num_vars_ptr], value);
(*num_vars_ptr)++;
return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @variable: the variable to remove
 * @num_vars_ptr: pointer to the num_vars variable
 * Return: returns 0 (success)
 */
int _unsetenv(char *variable, int *num_vars_ptr)
{
#define MAX_ENV_VARS 100
#define MAX_VAR_LENGTH 50
#define MAX_VALUE_LENGTH 100
char env_vars[MAX_ENV_VARS][MAX_VAR_LENGTH];
char env_vals[MAX_ENV_VARS][MAX_VALUE_LENGTH];
int i, j;

for (i = 0; i < *num_vars_ptr; i++)
{
if (_strcmp(env_vars[i], variable) == 0)
{
for (j = i; j < *num_vars_ptr - 1; j++)
{
_strcpy(env_vars[j], env_vars[j + 1]);
_strcpy(env_vals[j], env_vals[j + 1]);
}
(*num_vars_ptr)--;
return (0);
}
}
perror("Variable not found");
return (-1);
}
