#include "shell.h"

/**
  * main - entry point of the program
  * @ac: argument count
  * @argv: argument variants
  * Return: always 0
  */

int main(int ac, char **argv)
{
	char *command_line = NULL, **commands;
	int status = 0, idx_num = 0;
	(void) ac;
	/*(void) argv;*/

	while (1)
	{
		command_line = read_cmdLine();

		if (command_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx_num++;

		commands = tokenize_cmdLine(command_line);

		if (!commands)
			continue;

		status = execute_commands(commands, argv, idx_num);
	}
	return (0);

}
