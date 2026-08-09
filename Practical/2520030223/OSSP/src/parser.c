#include <stdio.h>
#include <string.h>
#include "parser.h"

void parse_command(char *command, char *args[]) {
    int i = 0;

    char *token = strtok(command, " ");

    while (token != NULL && i < MAX_ARGS - 1) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
}
