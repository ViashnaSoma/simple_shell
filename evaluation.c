#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Implement your logic to check if the command is a built-in command
 * Implement your logic to execute the built-in command based on the provided 'command' structure
 * command not there show "invalid comman"
 *
 * Return 1 if it is a built-in command, 0 otherwise
 */
void eval(command *command_struct)
{
	char checkpath[20] = "/bin/", *new_path;

	void (*func)(command *command_struct) = is_builtin(command_struct->argv[0]);

	if (func)
	{
		func(command_struct);
	}
	else
	{
		new_path = handle_path(command_struct, checkpath);
		exec(command_struct, new_path);
	}
}
