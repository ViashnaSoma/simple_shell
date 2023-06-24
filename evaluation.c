#include "shell.h"
#include <unistd.h>
#include <stdio.h>

/**
 * eval - calculates if it is built in or system command and takes action
 * @cmd_struct: structure of command
 * Return: no return value
 */

void eval(cmd *cmd_struct)
{
	char checkpath[20] = "/bin/", *new_path;

	void (*func)(cmd *cmd_struct) = is_builtin(cmd_struct->argv[0]);

	if (func != NULL)
	{
		func(cmd_struct);
	}
	else
	{
		new_path = handle_path(cmd_struct, checkpath);
		execute(cmd_struct, new_path);
	}
}
