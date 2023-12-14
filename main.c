#include "header.c"

/**
  * main - entry point of the program
  * Return: always 0
  */

int main()
{
/*	char *commandLine, **myCommands;*/
	int status;
	char *myCommand, **myCommands;
	pid_t myChild_pid;

	while (1)
	{
		write(1,"#cisfun$ ", 9);

/*		
		commandLine = _printMyPrompt();

		if (strcmp(commandLine, "exit") == 0)
			exit(0);

		myCommands = tokenize_command(commandLine);

		find_myCommand(myCommands, environ);
*/

		myCommand = _printMyPrompt();
		myCommands = malloc(2 * sizeof(char *));
		myCommands[0] = myCommand;
		myCommands[1] = NULL;
		
		if (myCommand == NULL)
		{
			free(myCommand);
			free(myCommands);
			write(1, "\n", 1);
			exit(0);
		}
		
		myChild_pid = fork();

		if (myChild_pid == -1)
		{
			perror("./shell");
			return (0);
		}
	
		else if (myChild_pid == 0)
		{
			if (execve(myCommand, myCommands, environ) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
			myChild_pid = wait(&status);

		free(myCommand);
		free(myCommands);
	}

	/*free(commandLine);
	free(myCommands);*/
	return (0);
}

