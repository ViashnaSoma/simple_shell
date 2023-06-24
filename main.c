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
	int read_byte;
	const char *display = "spshell> ";
	size_t num_bytes = sizeof(display), line_len = 1024;

	if (argc > 1)
	{
		exit(0);
	}
	for (;;)
	{
		input = malloc(100);
		write(0, display, num_bytes);
		read_byte = getline(&input, &line_len, stdin);
		if (read_byte == -1)
		{
			free(input);
			return (0);
		}
		else if (read_byte > 1)
		{
			input[read_byte - 1] = '\0';
			if (input)
			{
				parse(input, environ, argv[0]);
			}
			free(input);
		}
	}
}
