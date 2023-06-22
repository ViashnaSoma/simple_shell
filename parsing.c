#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * parsing - separates words from input based on
 * spaces and sends for evaluation
 * @input: string that needs to be tokenised
 * @envrn: the global environment
 * @normal: name of executable file
 * Return: nothing
 */

void parsing(char *input, char **envrn, char *normal)
{
	const char *space = " ";
	char *holder;
	command *command_struct = malloc(sizeof(command));

	
}
