#ifndef HEADER_C
#define HEADER_C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
  * environ - the line declares an external variable
  * it is a pointer to an array of strings rep the environment variables
  * used to pass the current environment to the child process
  */
extern char **environ;

int _putchar(char c);
char * _printMyPrompt(void);
char ** tokenize_command(char *commandLine);
void find_myCommand(char **myCommands, char **environ);
int fork_myParent(char **myCommands, char **environ, char *full_path);
int myChild_process(char **my_argv, char **environ, char *full_path);
int parent_wait();

#endif
