#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define DELIM " \t\n"
extern char **environ;

/* _strdup - function to duplicate string */
char *_strdup(const char *my_str);

/* _strcmp - function to compare two strings */
int _strcmp(char *my_str1, char *my_str2);

/* _strlen - function to get string length */
int _strlen(char *my_str);

/* _strcat - function to concatenate 2 strings */
char *_strcat(char *my_dest, char *my_src);

/* _strcpy - function to copy source string to destination string */
char *_strcpy(char *my_dest, char *my_src);

/* read_cmdLine - function to read the user command line */
char *read_cmdLine(void);

/* tokenize_cmdLine - function to put command line in a array of commands */
char **tokenize_cmdLine(char *command_line);

/* execute_commands - function to execute user commands */
int execute_commands(char **commands, char **argv, int idx_num);

/* free_arrayOf_string - frees array from memory */
void free_arrayOf_string(char **arr);

char *_getenv(char *variable);

char *get_mypath(char *my_command);

void printError(char *name, char *command, int idx_num);

char *_itoa(int idx_num);

void reverse_string(char *string, int str_len);

#endif
