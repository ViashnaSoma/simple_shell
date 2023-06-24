#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * main - starts the shell
 * @argc: arg count
 * @argv: arg array
 * Return: no return value
 */

int main(int argc, char **argv)
{
	int byte_read;
	char *command;
	const char *prompt = "sp_shell> ";
	size_t nbytes = sizeof(prompt), line_size = 1024;

	if (argc > 1)
	{
		exit(0);
	}
	while (1)
	{
		command = malloc(100);
		write(STDIN_FILENO, prompt, nbytes);
		byte_read = getline(&command, &line_size, stdin);
		if (byte_read == -1)
		{
			free(command);
			return (0);
		}
		else if (byte_read > 1)
		{
			command[byte_read - 1] = '\0';
			if (command)
				parse(command, environ, argv[0]);
			free(command);
		}
	}
}
