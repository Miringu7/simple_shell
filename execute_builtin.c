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

void execute_builtin(char **commands, char **argv, int *status, int idx_num)
{
	if (_strcmp(commands[0], "exit") == 0)
		exit_shell(commands, argv, status, idx_num);

	else if (_strcmp(commands[0], "env") == 0)
		print_myEnviron(commands, status);
}

/**
  * exit_shell - function to exit from shell
  * @commands: before exiting it will be freed
  * @argv: user input
  * @status: shell status
  * @idx_num: position of the command in the total no of commands executed
  */

void exit_shell(char **commands, char **argv, int *status, int idx_num)
{
	int exit_value = (*status);
	char *idx_str, err_message[] = ": exit: Illegal number: ";

	if (commands[1])
	{
		if (number_positive(commands[1]))
		{
			exit_value = _atoi(commands[1]);
		}

		else
		{
			idx_str = _itoa(idx_num);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx_str, _strlen(idx_str));
			write(STDERR_FILENO, err_message, _strlen(err_message));
			write(STDERR_FILENO, commands[1], _strlen(commands[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx_str);
			free_arrayOf_string(commands);
			return;
		}
	}
	free_arrayOf_string(commands);
	exit(exit_value);
}

/**
  * print_myEnviron - prints the env when called
  * @commands: after printing out it will be freed
  * @status: shell status
  */

void print_myEnviron(char **commands, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arrayOf_string(commands);

	(*status) = 0;
}
