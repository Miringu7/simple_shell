#include "shell.h"

/**
  * tokenize_command - use function strtok to get tokens
  * @commandLine: command line to be tokenized
  * Return: array of tokens
  */

char **tokenize_command(char *commandLine)
{
	int i = 0;
	char **my_argv, *delimiter = " ";
	char *token = strtok(commandLine, delimiter);

	my_argv = malloc(10 * sizeof(char *));
	if (my_argv == NULL)
	{
		perror("Error");
		return (NULL);
	}
	while (token != 0)
	{
		my_argv[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (my_argv[i] == NULL)
			return (NULL);

		strcpy(my_argv[i], token);
		i++;
		token = strtok(0, delimiter);
	}

	my_argv[i + 1] = NULL;
	return (my_argv);
}
