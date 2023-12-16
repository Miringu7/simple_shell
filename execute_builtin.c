#include "shell.h"

/**
  * builtin_cmd - function to check whether command is a builtin cmd
  * @my_command: command to be checked
  * Return: 0
  */

int builtin_cmd(char *my_command)
{
	char *builtins[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(my_command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
  * execute_builtin - executes the builtin command
  * @commands: user command 
  * @argv: user input 
  * @status: shell status
  * @idx_num: position of the command in the total no of commands executed
  */

void execute_builtin(char **commands, char **argv, int status, int idx_num)
{
	(void) argv;
	(void) idx_num;

	if (_strcmp(commands[0], "exit") == 0)
		exit_shell(commands, status);

	else if (_strcmp(commands[0], "env") == 0)
		print_myEnviron(commands, status);
}

/**
  * exit_shell - function to exit from shell
  * @commands: before exiting it will be freed
  * @status: shell status
  */

void exit_shell(char **commands, int status)
{
	free_arrayOf_string(commands);
	exit(status);
}

/**
  * print_myEnviron - prints the env when called
  * @commands: after printing out it will be freed
  * @status: shell status
  */

void print_myEnviron(char **commands, int status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arrayOf_string(commands);
}
