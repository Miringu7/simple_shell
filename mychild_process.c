#include "shell.h"

/**
  * myChild_process - uses execve() to execute commands
  * @my_argv: array of command strings to be executed
  * @environ: current environment
  * @full_path: full path to the command file
  * Return: 0 or (-1) incase of error
  */

int myChild_process(char **my_argv, char **environ, char *full_path)
{
	/*if (execve(my_argv[0], my_argv, environ) == -1)*/
	if (execve(full_path, my_argv, environ) == -1)
	{
		perror("Error");
		return (-1);
	}
	return (0);
}
