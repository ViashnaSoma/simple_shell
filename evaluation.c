#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Implement your logic to check if the command is a built-in command
 * Implement your logic to execute the built-in command based on the provided 'command' structure
 * command not there show "invalid comman"
 *
 * Return 1 if it is a built-in command, 0 otherwise
 */
int isBuiltInCommand(const char *cmd) 
{
    if (strcmp(cmd, "built-in-command") == 0) {
        return 1;
    }

    return 0;
}

void executeBuiltInCommand(const command *cmd) 
{
    printf("Executing built-in command...\n");
}

void executeNormalCommand(const command *cmd) 
{
    printf("Executing normal command...\n");
}

int main() {
    command cmd;
    cmd.argc = 3;
    cmd.argv[0] = "command_name";
    cmd.argv[1] = "arg1";
    cmd.argv[2] = "arg2";
    cmd.envrn = NULL;
    cmd.normal = NULL;

    const char *commandToCheck = "command_name";

    if (isBuiltInCommand(commandToCheck))
    {
        executeBuiltInCommand(&cmd);
    }
    else if (commandToCheck != NULL) {
        executeNormalCommand(&cmd);
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}
