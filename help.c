#include "shell.h"
#include <stdio.h>

/**
 * check_file - performs file checks
 * @file: parsed file to be checked
 * Return: 1 for success if file found, 0 for failure
 */

int check_file(char *file)
{
	struct stat check;

	if (stat(file, &check) != 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/**
 * get_len - retrieves string length
 * @s: pointer to string to be checked
 * Return: string length
 */
size_t get_len(char *s)
{
	size_t i = 0;

	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}
