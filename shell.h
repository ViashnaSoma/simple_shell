#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define ARGS_LIMIT 128

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct cmd - contains important arguments
 * cmd: the command
 * @env: pointers in array to environmental vars
 * @home: normal interface
 * @argv: arg array
 * @argc: arg count
 * Description: command structure
 */
typedef struct cmd
{
	int argc;
	char *home;
	char **env;
	char *argv[ARGS_LIMIT];
} cmd;

/**
 * struct builtins - built in func definitions
 * @func: the actual function
 * @instruction: gives the instructs
 * Descriiption: built in commands or gives structure
 */
typedef struct builtins
{
	void (*func)(cmd *);
	char *instruction;
} builtins_table;

void my_exit(cmd *cmd_struct);
void my_cd(cmd *cmd_struct);
void parse(char *command, char **env, char *home);
void execute(struct cmd *cmd_struct, char *new_path);
void (*is_builtin(char *command))(cmd *cmd_struct);
void eval(cmd *cmd_struct);
void my_env(cmd *cmd_struct);

char *check_var(char *env_var, char *var);
char *_strcat(char *dest, char *src);
char *handle_path(cmd *cmd_struct, char *checkpath);
int _strcmp(char *s1, char *s2);
char *get_env_var(char **environ, char *var);

size_t get_len(char *s);
int check_file(char *file);
#endif
