#include "shell.h"

/**
  * execute_commands - function to execute user commands
  * @commands: user commands array
  * @argv: argument variants
  * @idx_num: index number of the command
  * Return: execution status
  */

int execute_commands(char **commands, char **argv, int idx_num)
{
	char *my_path;
	pid_t child_process;
	int status;

	if (_strcmp(commands[0], "exit") == 0)
	{
		free_arrayOf_string(commands);
		exit(0);
	}
	my_path = get_mypath(commands[0]);
	if (!my_path)
	{
		printError(argv[0], commands[0], idx_num);
		free_arrayOf_string(commands);
		return (0);
	}

	child_process = fork();
	if (child_process == 0)
	{
		if (_strcmp(commands[0], "env") == 0)
		{
			_env();
			free_arrayOf_string(commands);
		}
		if (execve(my_path, commands, environ) == -1)
		{
			free(my_path), my_path = NULL;
			free_arrayOf_string(commands);
		}
	}
	else
	{
		waitpid(child_process, &status, 0);
		free(my_path), my_path = NULL;
		free_arrayOf_string(commands);
	}

	return (WEXITSTATUS(status));
}
