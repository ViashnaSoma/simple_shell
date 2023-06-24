#include "shell.h"
#include <stdio.h>

/**
 * execute - takes action on input
 * @cmd_struct: structure of command
 * @newpath: file path
 * Return: nothing
 */

void execute(cmd *cmd_struct, char *newpath)
{
	pid_t check_pid;

	if (check_file(newpath))
	{
		while ((check_pid = fork()) < 0)
		{
			perror("fork error");
			exit(1);
		}
		if (check_pid == 0)
		{
			if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
			{
				perror(cmd_struct->home);
				exit(1);
			}
		}
		else
		{
			wait(&check_pid);
		}
	}
	else if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
	{
		perror(cmd_struct->home);
	}
}
