#include "shell.h"

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
