#ifndef _SHELL_
#define _SHELL_
#define MAXARGS 128

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/**
 * struct cmd - holds all arguments and is most important.
 * cmd: command.
 * @home: home.
 * @argc: number of args
 * @argv: array of pointers to args
 * @env: array of pointers to env vars
 * Description: structure for commands.
 */
typedef struct cmd
{
	int argc;
	char *argv[MAXARGS];
	char **env;
	char *home;
} cmd;

/**
 * struct builtins - defines what our builtin functions
 * @instruction: instructions
 * @func: function.
 * Descriiption: structure or builtin commands.
 */
typedef struct builtins
{
	char *instruction;
	void (*func)(cmd *);
} builtins_table;

void parse(char *command, char **env, char *home);
void execute(struct cmd *cmd_struct, char *new_path);
void (*is_builtin(char *command))(cmd *cmd_struct);
void my_cd(cmd *cmd_struct);
void my_exit(cmd *cmd_struct);
void my_env(cmd *cmd_struct);
void eval(cmd *cmd_struct);

/* String functions that we can write to assist us */
int _strcmp(char *s1, char *s2);
char *get_env_var(char **environ, char *var);
char *check_var(char *env_var, char *var);
char *handle_path(cmd *cmd_struct, char *checkpath);
char *_strcat(char *dest, char *src);

/* Helpers */
int check_file(char *file);
size_t get_len(char *s);
#endif
