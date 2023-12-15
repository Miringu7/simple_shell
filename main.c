#include "shell.h"

/**
  * main - entry point of the program
  * Return: always 0
  */

int main(void)
{
	char *commandLine, **myCommands;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		commandLine = _printMyPrompt();

		if (strcmp(commandLine, "exit") == 0)
			exit(0);

		myCommands = tokenize_command(commandLine);

		find_myCommand(myCommands, environ);
	}
	free(commandLine);
	free(myCommands);
	return (0);
}

