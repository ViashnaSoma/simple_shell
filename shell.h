#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **envir;

/**
 * struct command - stores all arguments passed to function
 * command: command passed to function
 * @envrn: array containing pointers pointing to environ variables
 * @normal: original
 * @argc: argument count
 * @argv: array of arguments
 * Description: Command structure
 */
typedef struct command
{
	int argc;
	char *argv[128];
	char **envrn;
	char *normal;
} command;

#endif
