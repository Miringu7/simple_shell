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

