#include "main.h"

/**
 * print_environment - prints the env variable
 */


void print_environment(void)
{
extern char **environ;
int i = 0;
while (environ[i] != NULL)
{
_printf(environ[i]);
_printf("\n");
i++;
}
}
