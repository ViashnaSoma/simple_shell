#ifndef SHELL_H
#define SHELL_H
#define ARGS 128

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
	char *argv[ARGS];
	char **envrn;
	char *normal;
} command;
/**
 * struct builtins - gives builtin functions definitions
 * @instruction: holds the instructions
 * @func: function.
 * Description: builtin commands structure
 */
typedef struct builtins
{
	char *instruction;
	void (*func)(command *);
} builtins_table;

void parsing(char *input, char **envrn, char *normal);
void eval(command *command_struct);
void exec(command_struct, new_path);
#endif
