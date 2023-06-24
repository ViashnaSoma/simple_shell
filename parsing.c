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
	cmd *command_struct = malloc(sizeof(cmd));
	char *token;
	const char *delim = " ";

	command_struct->argc = 0;
	
	token = strtok(command, delim);
	/* Add token to argv list for execve */
	(command_struct->argv)[command_struct->argc] =  token;
	while (token != NULL)
	{
		command_struct->argc++;
		token = strtok(NULL, delim);
		(command_struct->argv)[command_struct->argc] =  token;
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
