#include "shell.h"

/**
  * fork_myParent - function to create child process using fork()
  * @myCommands: tokennized commands passed to child
  * @environ: current environment
  * @full_path: full path to the command file
  * Return: 0
  */
int fork_myParent(char **myCommands, char **environ, char *full_path)
{
	int status;
	pid_t myChild_pid;

	myChild_pid = fork();

	if (myChild_pid == -1)
	{
		perror("Error");
		return (1);
	}

	else if (myChild_pid == 0)
	{
		myChild_process(myCommands, environ, full_path);
	}

	else
	{
		waitpid(myChild_pid, &status, 0);
	}

	return (0);
}
