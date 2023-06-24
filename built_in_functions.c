#include "shell.h"

/**
 * shell_exit - leaves shell interface
 * @command_struct: command structure
 * Return: no return value
 */

void my_exit(cmd *command_struct)
{
	int i = 0;

	while (command_struct->argv[i])
	{
		free(command_struct->argv[i]);
		i = i + 1;
	}
	free(command_struct);
	exit(0);
}

/**
 * shell_env - displays the environment variables
 * @command_struct: command structure
 * Return: no return value
 */
void shell_env(cmd *command_struct)
{
	size_t env_bytes, num_letters;
	int i = 0;
	char line_new = '\n';

	while (command_struct->env[i])
	{
		num_letters = 0;
		while (command_struct->env[i][num_letters])
		{
			num_letters = num_letters + 1;
		}
		env_bytes = num_letters;
		write(STDOUT_FILENO, command_struct->env[i], env_bytes);
		i = i + 1;
		write(STDOUT_FILENO, &line_new, 1);
	}
}
