#include "shell.h"

/**
  * read_cmdLine - function to read the user command line
  * Return: user command line
  */

char *read_cmdLine(void)
{
	char *command_line = NULL;
	size_t cmd_len = 0;
	ssize_t char_read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	char_read = getline(&command_line, &cmd_len, stdin);
	if (char_read == -1)
	{
		free(command_line);
		return (NULL);
	}
	return (command_line);
}
