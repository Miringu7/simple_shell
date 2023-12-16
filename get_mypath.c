#include "shell.h"

/**
  * get_mypath - function to locate the path of input command
  * @my_command: command to be checked for presence
  * Return: if path found returns path, else NULL
  */

char *get_mypath(char *my_command)
{
	char *my_path, *token_dir, *env;
	int i;
	struct stat st;

	for (i = 0; my_command[i]; i++)
	{
		if (my_command[i] == '/')
		{
			if (stat(my_command, &st) == 0)
				return (_strdup(my_command));
			return (NULL);
		}
	}

	env = _getenv("PATH");
	token_dir = strtok(env, ":");

	while (token_dir != 0)
	{
		my_path = malloc(_strlen(token_dir) + _strlen(my_command) + 2);

		if (my_path)
		{
			_strcpy(my_path, token_dir);
			_strcat(my_path, "/");
			_strcat(my_path, my_command);

			if (stat(my_path, &st) == 0)
			{
				free(env);
				return (my_path);
			}
			free(my_path), my_path = NULL;
			token_dir = strtok(0, ":");
		}
	}
	free(env);
	return (NULL);
}
