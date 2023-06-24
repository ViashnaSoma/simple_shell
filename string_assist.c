#include "shell.h"
#include <stdio.h>

/**
 * get_env_var - retrieves the env var
 * @environ: parameter for environ
 * @var: parameter for var
 * Return: var for environ
 */

char *get_env_var(char **environ, char *var)
{
	char *var_environ, *end_var;
	int i = 0;

	while ((var_environ = environ[i]) != NULL)
	{
		end_var = check_var(var_environ, var);
		if (end_var)
		{
			return (end_var);
		}
		i++;
	}
	return (NULL);
}

/**
 * _strcmp - takes two strings and compares
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * Return: -15 - for s1 > s2, 15 for s2 > s1, 0 for s1 = s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, o = 0;

	while (o == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		o = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (o);
}
/**
 * check_var - checks environment variable.
 * @env_var: environment variable parameter.
 * @var: variable parameter.
 * Return: environmen variable
 */

char *check_var(char *env_var, char *var)
{
	int letter = 0;

	while (var[letter] != 0)
	{
		if (env_var[letter] != var[letter])
		{
			return (NULL);
		}
		letter++;
	}
	return (&env_var[letter + 1]);
}

/**
 * handle_path - handles PATH.
 * @cmd_struct: command structure.
 * @checkpath: filename for command
 * Return: void.
 */

char *handle_path(cmd *cmd_struct, char *checkpath)
{
	int env_count = 0, letter_count = 0;
	char *new_path, *env_path;

	env_path = get_env_var(cmd_struct->env, "PATH");
	if (env_path)
	{
		while (env_path[env_count] != 0 && cmd_struct->argv[0][0] != '.'
		&& cmd_struct->argv[0][0] != '/')
		{
			if (checkpath[letter_count] == env_path[env_count])
			{
				letter_count++;
				if (letter_count == 4)
				{
					new_path = _strcat(checkpath, cmd_struct->argv[0]);
					return (new_path);
				}
			}
			else
			{
				letter_count = 0;
			}
			env_count++;
		}
	}
	return (cmd_struct->argv[0]);
}

/**
 * _strncat - Appends n characters from src to dest
 * @dest: String pointer for destination
 * @src: String pointer for source
 * @n: Number of characters to append from src
 * Return: dest - string pointer to destination
 */

char *_strncat(char *dest, char *src, int n)
{
	int len_d = 0, len_s = 0;

	while (*(dest + len_d) != 0)
	{
		len_d++;
	}
	while (*(src + len_s) != 0 && len_s < n)
	{
		*(dest + len_d) = *(src + len_s);
		len_d++;
		len_s++;
	}
	*(dest + len_d) = 0;
	return (dest);
}
