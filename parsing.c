#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * parse - Tokenizes the string (splits words based on
 * space character) and sends to eval.
 * @command: command to be tokenized.
 * @env: global environment
 * @home: filename of executable
 * Return: no return
 */

void parse(char *command, char **env, char *home)
{
	cmd *cmd_struct = malloc(sizeof(cmd));
	char *token;
	const char *delim = " ";

	cmd_struct->argc = 0;
	/* Tokenize command string */
	token = strtok(command, delim);
	/* Add token to argv list for execve */
	(cmd_struct->argv)[cmd_struct->argc] =  token;
	while (token != NULL)
	{
		cmd_struct->argc++;
		token = strtok(NULL, delim);
		(cmd_struct->argv)[cmd_struct->argc] =  token;
	}
	cmd_struct->env = env;
	cmd_struct->home = home;
	/**
	 * Ensure Command is tokenized
	 * while (cmd_struct->argv[count] != NULL){
	 * printf("%s\n", cmd_struct->argv[count]);
	 * count++;}
	*/
	if (cmd_struct->argc)
	{
		eval(cmd_struct);
		free(cmd_struct);
	}
	else
	{
		exit(0);
	}
}
