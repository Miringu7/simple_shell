#include "shell.h"

/**
  * execute_commands - function to execute user commands
  * @commands: user commands array
  * @argv: argument variants
  * Return: execution status
  */

int execute_commands(char **commands, char **argv)
{
	pid_t child_process;
	int status;

	child_process = fork();
	if (child_process == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
		{
			perror(argv[0]);
			free_arrayOf_string(commands);
			exit(0);
		}
	}
	else
	{
		waitpid(child_process, &status, 0);
		free_arrayOf_string(commands);
	}

	return (WEXITSTATUS(status));
}

