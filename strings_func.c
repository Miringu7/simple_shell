#include "shell.h"

/**
  * _strdup - function to duplicate string
  * @my_str: string to be duplicated
  * Return: duplicated string
  */

char *_strdup(const char *my_str)
{
	char *dup;
	int i, str_len = 0;

	if (my_str == NULL)
		return (NULL);
	while (*my_str != '\0')
	{
		str_len++;
		my_str++;
	}

	my_str = my_str - str_len;
	dup = malloc(sizeof(char) * (str_len + 1));

	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= str_len; i++)
		dup[i] = my_str[i];

	return (dup);
}

/**
  * _strcmp - function to compare two strings
  * @my_str1: 1st string to be compared
  * @my_str2: 2nd string to be compared
  * Return: the difference
  */

int _strcmp(char *my_str1, char *my_str2)
{
	int diff;

	diff = (int)*my_str1 - (int)*my_str2;
	while (*my_str1)
	{
		if (*my_str1 != *my_str2)
			break;
		my_str1++;
		my_str2++;
		diff = (int)*my_str1 - (int)*my_str2;
	}
	return (diff);
}


/**
  * _strlen - function to get string length
  * @my_str: string to be used
  * Return: the string length
  */

int _strlen(char *my_str)
{
	int str_len = 0;

	while (my_str[str_len])
		str_len++;
	return (str_len);
}

/**
  * _strcat - function to concatenate 2 strings
  * @my_dest: destination for the final string
  * @my_src: the source string
  * Return: the final string in my_dest
  */

char *_strcat(char *my_dest, char *my_src)
{
	char *tmp = my_dest;

	while (*tmp)
		tmp++;

	while (*my_src)
	{
		*tmp = *my_src;
		tmp++;
		my_src++;
	}
	*tmp = *my_src;

	return (my_dest);
}

/**
  * _strcpy - function to copy source string to destination string
  * @my_dest: destination for the final string
  * @my_src: the source string
  * Return: the final string in my_dest
  */

char *_strcpy(char *my_dest, char *my_src)
{
	int i = 0;

	while (my_src[i])
	{
		my_dest[i] = my_src[i];
		i++;

	}
	my_dest[i] = '\0';
	return (my_dest);
}
