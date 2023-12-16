#include "shell.h"

/**
  * _env - function to print env when called
  * Return: void
  */

void _env(void)
{
	int i;
	char *temp;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		write(STDIN_FILENO, temp, _strlen(temp));
		write(STDIN_FILENO, "\n", 1);
		free(temp);
	}
}
