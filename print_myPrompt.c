#include "header.c"

/**
  * _printMyPrompt - prints prompt and user command to screen
  * 
  * Return: scanned command on screen
  */

char * _printMyPrompt(void)
{
	char *commandLine = NULL;
	size_t len = 0;
	ssize_t charRead;

	charRead = getline(&commandLine, &len, stdin);
	if (charRead == -1)
	{
		free(commandLine);
		return (NULL);
	}
	if (charRead > 0 && commandLine[charRead - 1] == '\n')
		commandLine[charRead - 1] = '\0';

	return (commandLine);
}
