#include "shell.h"

/**
 * exec - executes the system calls
 * @command_struct: structure of command
 * @newpath: file path
 * Return: nothing
 */

void exec(command_struct, new_path)
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
			if (execve(newpath, command_struct->argv, command_struct->envrn) < 0)
			{
				perror(command_struct->normal);
				exit(1);
			}
		}
		else
		{
			wait(&check_pid);
		}
	}
	else if (execve(newpath, command_struct->argv, command_struct->envrn) < 0)
	{
		perror(command_struct->normal);
	}
}
