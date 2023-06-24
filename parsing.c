#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * parse - splits words up and send to eval
 * @command: command passed to be split
 * @env: environ
 * @home: executable filename
 * Return: nothing
 */

void parse(char *command, char **env, char *home)
{
	char *holder;
	cmd *command_struct = malloc(sizeof(cmd));
	const char *space = " ";

	command_struct->argc = 0;
	
	holder = strtok(command, space);
	
	(command_struct->argv)[command_struct->argc] =  holder;
	while (holder)
	{
		command_struct->argc++;
		holder = strtok(NULL, space);
		(command_struct->argv)[command_struct->argc] =  holder;
	}
	command_struct->env = env;
	command_struct->home = home;
	
	if (command_struct->argc)
	{
		eval(command_struct);
		free(command_struct);
	}
	else
	{
		exit(0);
	}
}
