#include "shell.h"

/**
  * free_arrayOf_string - frees array from memory
  * @arr: array to be freed
  * Return: void
  */

void free_arrayOf_string(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
		free(arr[i]), arr[i] = NULL;

	free(arr), arr = NULL;
}

/**
  * printError - prints an error message on the output
  * @name: argv[0]
  * @command: user command commands[0]
  * @idx_num: index number of the command
  * Return: void
  */

void printError(char *name, char *command, int idx_num)
{
	char *index, *err_message = ": not found\n";

	index = _itoa(idx_num);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, err_message, _strlen(err_message));

	free(index);
}

/**
  * _itoa - function to convert integer to string
  * @idx_num: number to be changed to a string
  * Return: the index number as a string
  */

char *_itoa(int idx_num)
{
	char idx_string[20];
	int i = 0;

	if (idx_num == 0)
		idx_string[i++] = '0';
	else
	{
		while (idx_num > 0)
		{
			idx_string[i++] = (idx_num % 10) + '0';
			idx_num /= 10;
		}
	}

	idx_string[i] = '\0';
	reverse_string(idx_string, i);

	return (_strdup(idx_string));
}

/**
  * reverse_string - function to reverse the string outline
  * @string: string to be reversed
  * @str_len: the string length
  * Return: void
  */

void reverse_string(char *string, int str_len)
{
	char temp;
	int start = 0;
	int end = str_len - 1;

	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
	}
}
