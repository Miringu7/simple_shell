#include "shell.h"

/**
  * _getenv - function that gets the environment
  * @variable: variable to be checked if present in environ
  * Return: if variable matches key in environ return value of key else NULL
  */

char *_getenv(char *variable)
{
	char *temp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(temp);
			return (env);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}

/**
  * _atoi - converts string numbers to integers
  * @str: string number to be converted
  * Return: number converted
  */

int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
