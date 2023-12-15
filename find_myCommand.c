#include "shell.h"

/**
  * find_myCommand - function to find if the user command exists
  * @myCommands: user command from stdin to be checked
  * @environ: current environment
  * Description: if command exists, fork() will be called and command executed
  * access: function which checks if path provided exists
  * Return: void
  */

void find_myCommand(char **myCommands, char **environ)
{
	char *path_copy, *token, *command_path;
	const char *path = getenv("PATH");

	if (access(myCommands[0], F_OK) == 0)
		fork_myParent(myCommands, environ, myCommands[0]);

	else
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		path_copy = strdup(path);

		if (path_copy == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			char full_path[256];

			command_path = myCommands[0];

			snprintf(full_path, sizeof(full_path), "%s/%s", token, command_path);
			if (access(full_path, F_OK) == 0)
			{
				fork_myParent(myCommands, environ, full_path);
				break;
			}
			token = strtok(NULL, ":");
		}
	}
}
