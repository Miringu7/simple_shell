#include "shell.h"

/**
  * tokenize_cmdLine - function to put command line in a array of commands
  * @command_line: command string to tokenize
  * Return: the commands array
  */

char **tokenize_cmdLine(char *command_line)
{
	char *token = NULL, **commands, *temp = NULL;
	int cmd_num = 0, i = 0;

	if (!command_line)
		return (NULL);

	temp = _strdup(command_line);
	token = strtok(temp, DELIM);
	if (token == NULL)
	{
		free(temp), temp = NULL;
		free(command_line), command_line = NULL;
		return (NULL);
	}

	while (token)
	{
		cmd_num++;
		token = strtok(NULL, DELIM);
	}
	free(temp), temp = NULL;
	commands = malloc(sizeof(char *) * (cmd_num + 1));

	if (!commands)
	{
		free(command_line), command_line = NULL;
		return (NULL);
	}
	token = strtok(command_line, DELIM);

	while (token)
	{
		commands[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(command_line), command_line = NULL;
	commands[i] = NULL;

	return (commands);
}
