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
	char *input;
	int byte_read;
	size_t nbytes = sizeof(prompt), line_size = 1024;
	const char *prompt = "spshell> ";

	if (argc > 1)
	{
		exit(0);
	}
	while (1)
	{
		input = malloc(100);
		write(STDIN_FILENO, prompt, nbytes);
		byte_read = getline(&input, &line_size, stdin);
		if (byte_read == -1)
		{
			free(input);
			return (0);
		}
		else if (byte_read > 1)
		{
			input[byte_read - 1] = '\0';
			if (input)
				parse(input, environ, argv[0]);
			free(input);
		}
	}
}
