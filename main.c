#include <sys/wait.h>
#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - point of entry for shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for failure
 */

int main(int argc, char **argv)
{
	const char *display = "simpleshell> ";
	char *input;
	size_t len_display = sizeof(display), max_line_size = 1024;
	int line_len;

	if (argc > 1)
	{
		exit(0);
	}

	for (;;)
	{
		input = malloc(200);
		write(0, display, len_display);
		line_len = getline(&input, &max_line_size, stdin);
		if (line_len == -1)
		{
			free(input);
			return (0);
		}
		else if (line_len > 1)
		{
			input[line_len - 1} = '\0';
			if (input)
			{
				parsing(input, envir, argv[0]);
			}
			free(input);
		}
	}
		
}
